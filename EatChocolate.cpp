/// \brief 腾讯 2019 在线编程题，吃巧克力
///
/// 出差N天，留下M块巧克力，每天吃的巧克力数量不少于前一天吃的一半，第一天最多能吃多少块巧克力？
/// 输入两个整数，表示出差天数N(N<=50000)和巧克力数量M(N<=M<=100000)，比如 3 7
/// 输出第一天最多能吃多少快巧克力，比如 4
///
/// \author HSDB
/// \date 2018-04-10
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    int diff=M-N;
    int x,n=N;

    if(N==1){
        cout<<M;
    }
    else if(diff==0){
        cout<<1;
    }else if(diff==1 || diff==2){
        cout<<2;
    }else{
        x=ceil(diff/2.0);
        cout<<x<<" ";
        while(--n){
            x=ceil(x/2.0);
            if(x<=2)
            {
                break;
            }
            cout<<x<<" ";
        }
    }
    cin.get();
    return 0;
}