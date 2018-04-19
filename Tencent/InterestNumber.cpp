/// \brief 有趣的数字
///
/// 小 Q 今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？
/// 
///
/// \author HSDB
/// \date 2018-04-19

/// 输入描述：
/// 对于每组测试数据：
/// N - 本组测试数据有n个数
/// a1,a2...an - 需要计算的数据
/// 1<=N<=100000,0<=ai<=INT_MAX.

/// 输出描述：
/// 对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。

/// 输入：
/// 6
/// 45 12 45 32 5 6

/// 输出：
/// 1 2
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int N;
    while(cin>>N)
    {
        vector<int> array(N);
        for(int i=0;i<N;i++)
            cin>>array[i];
        if(N==1)
        {
           cout<<0<<" "<<0<<endl;
           continue;
        }
        // 首先进行快速排序
        sort(array.begin(),array.end());
        // 如果全部相等，则是 C_N_2
        if(array[0]==array[N-1])
        {
            int num=N*(N-1)/2;
            cout<<num<<" "<<num<<endl;
            continue;
        }
        // 分别统计最大、最小元素的个数
        int maxNum=count(array.begin(),array.end(),array[N-1]);
        int minNum=count(array.begin(),array.end(),array[0]);
        // 则差最大的对数为
        int max=maxNum*minNum;
        // 求出最小的差
        int minValue=array[1]-array[0];
        for(int i=1;i<N;i++)
            if(array[i]-array[i-1]<minValue)
                minValue=array[i]-array[i-1];
        // 再次遍历统计最小差的对数
        int min=0;
        for(int i=1;i<N;i++)
            for(int j=i-1;j>=0;j--)             // 可以处理有些值相等的情况
                if(array[i]-array[j]==minValue)
                    min++;
                else
                    break;
        cout<<min<<" "<<max<<endl;
        }
    return 0;
}