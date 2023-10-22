#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void showDP(vector<vector<int>> dp);
void LCS(string A,string B)
{
    int sz_A=A.size();
    int sz_B=B.size();
    vector<vector<int>> dp(sz_A,vector<int>(sz_B,0));
    // for(int i=0;i<sz_B;i++)
    // {
    //     dp[0][i]=1;
    // }
    // for(int i=0;i<sz_A;i++)dp[i][0]=1;
    #if 1
    for(int i=0;i<sz_A;i++)
    {
        for(int j=0;j<sz_B;j++)
        {
            
            if(A[i]==B[j])
            {
                if(i==0||j==0)
                {
                    dp[i][j]=1;
                }
                else
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{

                if(i&&j)
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
                
            }
        }
    } 
    cout<<"最长公共子序列  "<<dp[sz_A-1][sz_B-1];
    #endif
    showDP(dp);
}
int main(){
    LCS("abcbdab","bdcaba");
    return 0;
}
void showDP(vector<vector<int>> dp)
{
    int sz_A=dp.size();
    int sz_B=dp[0].size();
    cout<<endl;
    for(int i=0;i<sz_B;i++)
    {
        for(int j=0;j<sz_A;j++)
        {
            cout<<dp[j][i]<<"  ";
        }
        cout<<endl;
    }

}