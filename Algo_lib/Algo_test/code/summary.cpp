#include<vector>
#include<algorithm>
#include<set>
#include<iostream>
#include<list>
using namespace std;
void move(int a,int b){

}
void hanuo(int src,int mid,int dst,int n)
{
    if(n==1)
    {
        move(src,dst);//1
    }
    else{
        hanuo(src,dst,mid,n-1);
        move(src,dst);//1
        hanuo(mid,src,dst,n-1);
    }
}
void solve5()
{
    hanuo(0,1,2,3);
}
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void dfs(vector<vector<int>> &matrix,int x0,int y0,int x,int y,vector<vector<int>>& path)
{
    path.push_back({x-x0,y-y0});
   int k,nx,ny;
    for( k=0;k<4;k++)
    {
        nx=x+dx[k];//x.
         ny=y+dy[k];
        if(nx>=0&&  ny>=0&&nx<matrix.size()&&ny<matrix[0].size()&&matrix[nx][ny]==1)
        {
            matrix[nx][ny]=0;
            dfs(matrix,x0,y0,nx,ny,path);//there
        }

    }
}
int solve6(vector<vector<int>> &matrix)
{
    if(matrix.size()==0||matrix[0].size()==0)
    {
        return 0;
    }
    set<vector<vector<int>>> paths;
    int m=matrix.size(),n=matrix[0].size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==1)
            {
                matrix[i][j]=0;
                vector<vector<int>> path;
                dfs(matrix,i,j,i,j,path);
                paths.insert(path);
            }
        }
    }
    return paths.size();
}
int solve4(vector<vector<int>>& matrix)
{

    int max_size=0,i,j;
    vector<vector<int> > dp(matrix.size(),vector<int>(matrix[0].size()));
    for( i=0;i<matrix.size();i++)
    {
        for( j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j]==1)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=1;

                }
                else{
                    dp[i][j]=(min(matrix[i-1][j],matrix[i][j-1]),matrix[i-1][j-1])+1;
                }
            }
                    max_size=max(max_size,dp[i][j]);

        }
    }
    return max_size;
}
long long supermod(int x,int y,int n)
{
    if(x==0)return 0;
    if(y==0)return x%n;
    if(y==1)return x*10%n;
    if(y%2)
    {
       return  (supermod(x,y/2,n)*supermod(1,y/2+1,n))%n;
    }
    else{
        return (supermod(x,y/2,n)*supermod(1,y/2,n))%n;
    }
}
int solve2(string a,string b,int n)
{
    long result=0;
    for(int i=0;i<a.size();i++)
    {
        int temp=supermod(a[i]-'0',a.size()-i-1,n);
        result=(temp+result)%n;
    }
    for(int j=0;j<b.size();j++)
    {
        int temp=supermod(b[j]-'0',b.size()-j-1,n);
        result=(temp+result)%n;
    }
    return result;

}
int main()
{
    vector<vector<int> > matrix {
                                    vector<int>{1,1,0,1,1,},
                                    vector<int>{1,0,1,0,0,},
                                    vector<int>{0,1,0,0,1,},
                                    vector<int>{1,1,0,1,1,},
                                };
                cout<<"maze:solve6 :"<<solve6(matrix)<<endl;
    vector<vector<int> > matrix4 {
                                    vector<int>{1,0,1,0,0},
                                    vector<int>{1,0,1,1,1},
                                    vector<int>{1,1,1,1,1},
                                    vector<int>{1,0,0,1,0},
                                };

            
         cout<<"solve2: "<<solve2("122142323","123421323",19)<<endl;
        //  cout<<"solve2 of his: "<<solve("122142323","123421323",19)<<endl;
    cout<<"max of mine, length of the square: "<<solve4(matrix4);
              return 0;
}