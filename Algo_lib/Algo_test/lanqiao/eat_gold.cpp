
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,s=0;
	cin>>m>>n;
	int a[3001]={};//a储存输入的第i行的每个数，通过滚动数组降低空间复杂度
	int dp[2][3001]={};//dp存储第i和i-1行的最优取法的结果,同上降低空间复杂度 
	  
	for(int i=0;i<m;i++)
	 {
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
            if(i==0) dp[i%2][j]=a[j];//第一行没有前面的行，自身就是最大金币数，预处理 
            else
            {
                for(int k=0;k<n;k++)
                {
                if(j==k) continue;//同一列跳过 
                dp[i%2][j]=max(dp[i%2][j],dp[(i-1)%2][k]+a[j]);//动规取上一列可取的中的最多金币 
                }
            }
        }
     }
	for(int i=0;i<n;i++)
	s=max(s,dp[(m-1)%2][i]);//取最后一列中最多金币数的输出
	cout<<s;
}

