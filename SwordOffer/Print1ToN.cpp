/// \brief 打印从 1 到最大的 n 位数
///
/// 输入数字 n，按顺序打印出从 1 最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数即 999。
/// 目前没有调试出来
///
/// \author HSDB
/// \date 2018-04-18
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

void printNumber(char *number) {
    int index = 0;
    int len=strlen(number);
    while (index < len && number[index] == '0') index++;
    while (index < len) cout<<number[index++];
    cout<<endl;
}

void print1ToMaxOfNDigits(char *number, int digit) {
    int len=strlen(number);
    if (digit == len - 1) {
        printNumber(number);
        return;
    }
    for (int i = 0; i < 10; i++) {
        number[digit + 1] = (char) (i + '0');
        print1ToMaxOfNDigits(number, digit + 1);
    }
}

void print1ToMaxOfNDigits(int n) {
    if (n < 0) return;
    char *number = new char[n];
    print1ToMaxOfNDigits(number, -1);
    delete[] number;
}

void print_1_n(int n){

}

int main(){
    /*int arr[]={0,1,2,3};
    do{
        cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<endl;
    }while(next_permutation(arr,arr+3));*/

    print1ToMaxOfNDigits(2);
    return 0;
}