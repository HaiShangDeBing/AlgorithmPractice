/// \brief n 皇后问题
///
/// 在 nxn 的方格棋盘上，放置 n 个皇后，要求每个皇后不同行、不同列、不同左右对角线。
/// 
///
/// \author HSDB
/// \date 2018-04-10

/// 下面举例 4 皇后的算法步骤
/// 1.将第 1 个皇后放置在第 1 行的第 1 个空格里
/// 2.对于第 2 行，从第 1 个空格开始寻找不与第 1 行的皇后冲突的空格。找到的第一个不冲突的空格是第 2 个。
/// 3.对于第 3 行，这时已经找不到与之前放置的两个皇后不冲突的空格了。把当前行恢复初始状态，返回到上一行。
/// 4.在当前行皇后所占的空格之后寻找一个不与之前皇后冲突的位置。
///   有两种情况，如果找到了则把当前行的皇后移动到该位置，然后处理下一行。
///   如果直到最后当前行的最后一个空格也没有找合适的位置，则把当前行恢复初始状态，继续回溯到上一行。
/// 5.把最后一个皇后成功安置在最后一行，代表找到了一种可行解。返回步骤4。
/// 6.当需要回溯到第 0 行（表格之外）的时候代表已经找遍了所有可能的可行解。
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool check_queen(int queen[],int row,int col){
    for(int i=0;i<row;i++){
        // queen[i]==col判断是否同列，abs(queen[i]-col)==abs(i-row)判断是否在对角线，行列互减的绝对值是否相等
        if(queen[i]==col || abs(queen[i]-col)==abs(i-row))
            return false;
    }
    return true;
}

void place_queen(int queen[],int row,int n,int &cnt){
    if(row == n){
        cnt++;
    }else{
        for(int col=0;col<n;col++){
            if(check_queen(queen,row,col)){
                queen[row]=col;
                place_queen(queen,row+1,n,cnt);
            }
        }
    }
}
/*
/// 递归
int nQueen(int n){
    int *queen = new int[n];
    int cnt=0;
    place_queen(queen,0,n,cnt);
    delete[] queen;
    return cnt;
}
*/
/// 非递归
int nQueen(int n){
    int *queen = new int[n];
    int cnt=0;
    int row = 0;
    int col = 0;
    while(row<n){
        while(col<n){
            if(check_queen(queen,row,col)){
                queen[row]=col;                 //确定列数，开始下一行
                if(row==n-1){                   //找到一个解
                    cnt++;
                    break;
                }else{
                    row++;                      //继续确定下一行皇后位置，从第0列开始搜索
                    col=-1;
                }
            }
            col++;
        }
        if(row==0)                               //回溯完毕
            break;
        row--;                                  //回溯，把上一行皇后的位置往后移一列
        col = queen[row] + 1;
    }
    delete[] queen;
    return cnt;
}

int main(){
    int n;
    while(cin>>n){
        cout<<nQueen(n)<<endl;
    }
    return 0;
}