/// \brief 数值的整数次方
///
/// 给定一个 double 类型的浮点数 base 和 int 类型的整数 exponent。求 base 的 exponent 次方。
/// 
///
/// \author HSDB
/// \date 2018-04-18
#include <iostream>
using namespace std;

/// 把一个整数减去1，再和原整数做与运算，会把该整数最右边的一个1变成0。
/// 那么一个整数的二进制表示中由多少个1，就可以进行多少次这样的操作。
double power_exponent(double base,int exponent){
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;
    double res = power_exponent(base,exponent>>1);
    res *= res;
    // exponent 为奇数的时候
    if(exponent & 0x1 == 1)
        res *= base;
    return res;
}

int main(){
    int exponent;
    double base;
    while(cin>>base>>exponent)
        cout<<power_exponent(base,exponent)<<endl;
    return 0;
}