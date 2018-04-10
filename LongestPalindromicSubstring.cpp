#include <iostream>
#include <string>
using namespace std;
#define _MAX_LEN 1000
int max_len[_MAX_LEN][_MAX_LEN];
int main(){
    string s;
    while(cin>>s){
        string s1(s.rbegin(),s.rend());cout<<s1;
        for(int i=0;i<s.length();i++){
            max_len[i][0]=0;
            max_len[0][i]=0;
        }
        for(int i=1;i<s.length();i++){
            for(int j=1;j<s1.length();j++){
                if(s[i-1] == s1[j-1]){
                    max_len[i][j] = max_len[i-1][j-1]+1;
                }
                else{
                    max_len[i][j] = max(max_len[i-1][j],max_len[i][j-1]);
                }
            }
        }
        cout << s.length() - max_len[s.length()][s1.length()] << endl;
    }
    return 0;
}