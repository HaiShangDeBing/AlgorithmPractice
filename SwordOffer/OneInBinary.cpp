/// \brief 二进制中 1 的个数
///
/// 输入一个整数，输出该数二进制表示中 1 的个数。
/// 
///
/// \author HSDB
/// \date 2018-04-18
#include <iostream>
using namespace std;

/// 把一个整数减去1，再和原整数做与运算，会把该整数最右边的一个1变成0。
/// 那么一个整数的二进制表示中由多少个1，就可以进行多少次这样的操作。
int one_in_binary(int n){
    int cnt = 0;
    while (n != 0) {
        cnt++;
        n &= (n - 1);
    }
    return cnt;
}

int main(){
    int n;
    while(cin>>n)
        cout<<one_in_binary(n)<<endl;
    return 0;
}