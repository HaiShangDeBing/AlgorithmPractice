/// \brief 0/1 背包问题
///
/// 有 n 个重量分别为{w1,...wn}的物品，价值分别为{v1,...vn}，给定一个容量为 W 的背包。每个物品要么选中，要么不选中，
/// 要求选中的物品不仅能放到背包中，而且具有最大的价值。
///
///
/// \author HSDB
/// \date 2018-04-12
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//使得二进制数组每次加 1
void change(int b[],int n){
    for(int i=0;i<n;i++){
        if(b[i])
            b[i]=0;
        else{
            b[i]=1;
            break;
        }
    }
}

void knapsack(int w[],int v[],const int W,const int n){
    int all=pow(2,n);
    int maxSumW=0,maxSumV=0;
    int sumW=0,sumV=0;
    int maxi;
    vector<int> tempChoice,bestChoice;

    int* a=new int[n];
    int* b=new int[n];
    for(int i=0;i<n;i++){
        a[i]=i+1;
        b[i]=0;
    }

    for(int i=0;i<all;i++){
        for(int j=0;j<n;j++){
            if(b[j]){           //b 中为 1 的位对应的 a 中元素
                tempChoice.push_back(a[j]);
                sumW += w[j];
                sumV += v[j];
            }                              
        }
        change(b,n);
        if(sumW<=W){
            if(sumV>maxSumV){
                maxSumV = sumV;
                maxSumW = sumW;
                bestChoice = tempChoice;
            }
        }
        tempChoice.clear();
        sumW=0,sumV=0;
    }
    
    cout<<"best choice:{ ";
    for(auto i:bestChoice){
        cout<<i<<" ";
    }
    cout<<"},";
    cout<<"total weight: "<<maxSumW<<",total value: "<<maxSumV;

    delete[] a;
    delete[] b;
}
int main(){
    int n=4,W=7;
    int w[]={5,3,2,1};
    int v[]={4,4,3,1};
    knapsack(w,v,W,n);
    return 0;
}