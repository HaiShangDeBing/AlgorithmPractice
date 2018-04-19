/// \brief 构造回文
///
/// 把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
/// 
///
/// \author HSDB
/// \date 2018-04-19

/// 输入描述：
/// 输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000

/// 输出描述：
/// 对于每组数据，输出移位后的字符串。

/// 输入：
/// AkleBiCeilD

/// 输出：
/// kleieilABCD

#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    while(std::cin>>str){
         for(int i=0;i<str.size()-1;i++)
            for(int j=0;j<str.size()-1-i;j++)
                if((str[j]>='A'&&str[j]<='Z')&&(str[j+1]<'A'||str[j+1]>'Z')){
                    swap(str[j],str[j+1]);
                }
    cout<<str<<endl;
    }
    return 0;
}