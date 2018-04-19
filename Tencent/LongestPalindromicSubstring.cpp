/// \brief 构造回文
///
/// 给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
/// 
///
/// \author HSDB
/// \date 2018-04-19

/// 输入描述：
/// 输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.

/// 输出描述：
/// 对于每组数据，输出一个整数，代表最少需要删除的字符个数。

/// 输入：
/// abcda
/// google

/// 输出：
/// 2
/// 2
///     a b c d a
///   0 0 0 0 0 0
/// a 0 1 1 1 1 1
/// d 0 1 1 1 2 2
/// c 0 1 1 2 2 2
/// b 0 1 2 2 2 2
/// a 0 1 2 2 2 3
#include <iostream>
#include <string>
using namespace std;
#define _MAX_LEN 1000
int max_len[_MAX_LEN][_MAX_LEN];
int main(){
    string s;
    while(cin>>s){
        // 逆序字符串
        string s1(s.rbegin(),s.rend());
        // 初始化 max_len 数组
        for(int i=0;i<s.length();i++){
            max_len[i][0]=0;
            max_len[0][i]=0;
        }
        // 求这两个字符串的最长公共子序列
        // 其中，回文不一定是连续的，最长公共子序列也不一定是连续的。
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=s1.length();j++){
                if(s[i-1] == s1[j-1]){
                    max_len[i][j] = max_len[i-1][j-1]+1;                    //最长公共子序列加 1
                }
                else{
                    max_len[i][j] = max(max_len[i-1][j],max_len[i][j-1]);   // 不相等，则最长公共子序列是之前能够成的最大值
                }
            }
        }
        cout << s.length() - max_len[s.length()][s1.length()] << endl;
    }
    return 0;
}