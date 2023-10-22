#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n,m,arr[10];
    while(cin>>n)
    {
        memset(arr,0,sizeof(arr));//数组初始化为0
        for(int i=1;i<=n;i++)
        {
            m=i;
            while(m)//核心思路
            {
                arr[m%10]++;//统计出现次数
                m/=10;
            }
        }
        for(int i=0;i<10;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
    return 0;
}