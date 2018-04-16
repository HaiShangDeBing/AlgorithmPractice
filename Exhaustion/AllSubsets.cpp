/// \brief 输出集合的所有子集
///
/// 采用穷举法，n 个元素的集合的所有子集有 pow(2,n) 个，时间复杂度为 O(nx2^n)
///
/// \author HSDB
/// \date 2018-04-12
#include <iostream>
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

void all_subsets(int a[],int b[],const int n){
    int all=pow(2,n);
    cout<<"all subsets:"<<endl;
    for(int i=0;i<all;i++){
        cout<<"{ ";
        for(int j=0;j<n;j++){
            if(b[j])                        //输出 b 中为 1 的位对应的 a 中元素
                cout<<a[j]<<' ';
        }
        cout<<"}"<<endl;
        change(b,n);
    }
}

int main(){
    int n;
    while(cin>>n){
        int* a=new int[n];
        int* b=new int[n];
        for(int i=0;i<n;i++){
            a[i]=i+1;
            b[i]=0;
        }
        all_subsets(a,b,n);
        delete[] a;
        delete[] b;
    }
    return 0;
}