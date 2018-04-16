/// \brief 0/1 背包问题
///
/// 有 n 个重量分别为{w1,...wn}的物品，价值分别为{v1,...vn}，给定一个容量为 W 的背包。每个物品要么选中，要么不选中，
/// 要求选中的物品不仅能放到背包中，而且具有最大的价值。
///
///
/// \author HSDB
/// \date 2018-04-16
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void knapsack(int w[],int v[],const int W,const int n){
    //开辟动态二维数组
    int **f = new int*[n+1];
    for(int i=0;i<=n;i++){
        f[i] = new int [W+1]();
    }
    //f(i,j)表示前 i 件物品，背包容量为 j 时的最优值
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(j>=w[i]){
                f[i][j]=max(f[i-1][j-w[i]]+v[i],f[i-1][j]);
            }else{
                f[i][j]=f[i-1][j];
            }
        }
    }
    cout<<f[n][W]<<endl;//输出最优价值  
}

int main(){
    int n=5,W=10;
    int w[]={0,2,2,6,5,4};
    int v[]={0,6,3,5,4,6};
    knapsack(w,v,W,n);
    return 0;
}