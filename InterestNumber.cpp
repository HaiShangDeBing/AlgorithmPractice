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
        sort(array.begin(),array.end());
        if(array[0]==array[N-1])
        {
            int num=N*(N-1)/2;
            cout<<num<<" "<<num<<endl;
            continue;
        }
        int maxNum=count(array.begin(),array.end(),array[N-1]);
        int minNum=count(array.begin(),array.end(),array[0]);
        int max=maxNum*minNum;
        int minValue=array[1]-array[0];
        for(int i=1;i<N;i++)
            if(array[i]-array[i-1]<minValue)
                minValue=array[i]-array[i-1];
        int min=0;
        for(int i=1;i<N;i++)
            for(int j=i-1;j>=0;j--)
                if(array[i]-array[j]==minValue)
                    min++;
                else
                    break;    //这一步相当关键啊
        cout<<min<<" "<<max<<endl;
        }
    return 0;
}