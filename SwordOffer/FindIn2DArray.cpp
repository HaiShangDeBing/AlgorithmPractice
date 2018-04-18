/// \brief 二维数组中的查找
///
/// 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
/// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
///
/// \author HSDB
/// \date 2018-04-18
#include <iostream>
#include <cmath>
using namespace std;
/*
bool find_in_2d_array(int arr[][4],int col,int row,int number){
    //int m=sizeof(arr[0])/sizeof(int);  
    //int n=(sizeof(arr)/sizeof(int))/(sizeof(arr[0])/sizeof(int));     //求二维数组的长度有问题
    //cout<<m;
    if(arr!=NULL && row>0 && col >0){
        int r=0;
        int c=col-1;
        while(r < row && c>=0){
            if(arr[r][c] == number){                                   //选取右上角进行比较
                return true;
            }else if(arr[r][c] > number){                             //如果右上角比查找的数大，则舍去这一列
                c--;
            }else{                                                    //否则舍去这一行
                r++;
            }   
        }
    }
    return false;  
}
*/
bool find_in_2d_array(int *arr,int col,int row,int number){
    if(arr!=NULL && row>0 && col >0){
        int r=0;
        int c=col-1;
        while(r < row && c>=0){
            if(arr[r*col+c] == number){                                   //选取右上角进行比较
                return true;
            }else if(arr[r*col+c] > number){                             //如果右上角比查找的数大，则舍去这一列
                c--;
            }else{                                                    //否则舍去这一行
                r++;
            }   
        }
    }
    return false;  
}

int main(){
    int arr[4][4]={1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
    int number=7;
    cout<<find_in_2d_array((int *)arr,4,4,number);
    //cout<<find_in_2d_array(arr,4,4,number);
    return 0;
}