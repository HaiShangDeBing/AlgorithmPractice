/// \brief 背包问题
///
/// 有 n 个重量分别为{w1,...wn}的物品，价值分别为{v1,...vn}，给定一个容量为 W 的背包。
/// 每个物品可以取一部分装入背包，要求在不超过背包负重的前提下，使背包装入的总价值最大
///
///
/// \author HSDB
/// \date 2018-04-12
#include <iostream>
#include <algorithm>
using namespace std;

int Partition(double w[],double v[],int start,int end){
    int left=start,right=end;
    double temp1=w[start],temp2=v[start];
    while(left!=right){
        //从右往左找小于于基准值的数
        while(left<right && v[right]/w[right]<=temp2/temp1){
            right--;
        }
        w[left]=w[right];v[left]=v[right];                          //大于则前移
        //从左往右找大于基准值的数
        while(left<right && v[left]/w[left]>=temp2/temp1){
            left++;
        }
        w[right]=w[left];v[right]=v[left];                          //小于则后移
    }
    w[left]=temp1;v[left]=temp2;                                    //更新基准值
    return left;
}

void QuickSort(double w[],double v[],int start,int end){
    int i;
    if(start<end){
        i=Partition(w,v,start,end);
        QuickSort(w,v,start,i-1);
        QuickSort(w,v,i+1,end);
    }
}

double knapsack(int n,double w[],double v[],double W,double x[]){
    double V=0;                                         //总价值
    double weight=W;                                    //背包剩余重量
    int i=0;

    //初始化
    for(i=0;i<n;i++)
        x[i]=0;
    i=0;
    //物品 i 能够全部装入时循环
    while(w[i]<weight){
        x[i]=1;
        weight-=w[i];
        V+=v[i];
        i++;
    }
    //剩下的部分装入
    if(weight>0){
        x[i]=weight/w[i];
        V+=x[i]*v[i];
    }
    return V;
}

template<typename T>
void disp(T arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int n=5;
    double W=100,V;
    double *x=new double[n];
    double w[]={10,20,30,40,50};
    double v[]={20,30,66,40,60};
    QuickSort(w,v,0,n-1);
    disp(v,n);
    disp(w,n);
    V=knapsack(n,w,v,W,x);
    disp(x,n);
    cout<<V;
    delete [] x;
    return 0;
}