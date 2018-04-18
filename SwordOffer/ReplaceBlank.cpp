/// \brief 替换空格
///
/// 请实现一个函数，将一个字符串中的空格替换成“%20”。
/// 例如，当字符串为 We Are Happy. 则经过替换之后的字符串为 We%20Are%20Happy。
///
/// \author HSDB
/// \date 2018-04-18
#include <iostream>
#include <string>
using namespace std;

void replace_blank(string &str){
    int len=str.size();
    if(str.empty())
        return;
    string::size_type pos;
    while((pos=str.find(" "))!=string::npos){
        str.erase(pos,1);
        str.insert(pos,"%20");
    }
}

int main(){
    string str="We Are Happy";
    replace_blank(str);
    cout<<str;
    return 0;
}