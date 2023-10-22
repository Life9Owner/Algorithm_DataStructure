// 13006. 不同岛屿的数量 - 搜索
#include <set>
#include<vector>
#include<iostream>
using namespace std;
// void dfs(vector<vector<int>>& matrix,int x0,int y0,int x,int y,set<vector<vector<int>>>& paths);
#if 1
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
void dfs(vector<vector<int>>& matrix, int x0, int y0, int x, int y, vector<vector<int>>& path) {
    path.push_back({x-x0, y-y0});   //路径记录相对坐标
    int m = matrix.size(), n=matrix[0].size();
    int k, nx, ny;

    for(k = 0; k < 4; ++k)
    {
        nx = x + dx[k];
        ny = y + dy[k];
        if(nx>=0 && nx<m && ny>=0 && ny<n && matrix[nx][ny]==1)
        {
            matrix[nx][ny] = 0;   //访问过 become the sea
            dfs(matrix, x0, y0, nx, ny, path);
        }
    }
   
}
#endif
int solve(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty())  return 0;

    set<vector<vector<int>>> paths; // 每个岛屿存储一个搜索路径，利用set去重
    // set can keep the two dimension vector ,so many two dimensions.
    //that is the answer of so many circumstances. just remove the repeated ones
    int m = matrix.size(), n=matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1)//岛屿
            {
                vector<vector<int>> path;
                matrix[i][j] = 0;  
                dfs(matrix, i, j, i, j, path);
                paths.insert(path);//insert the two dimension vector
                // to become vectors 
            }
        }
    }
    return paths.size();
}
#if 0
void dfs(vector<vector<int>>& matrix,int x0,int y0,int x,int y,set<vector<vector<int>>>& paths)
{
    vector<vector<int>> path;
     
     if(x<0||x>matrix[0].size()-1||y<0|| y>matrix.size()-1||matrix[x][y]==0)
     {
        return;
     }
     path.push_back({x-x0,y-y0});
    paths.insert(path);
    dfs(matrix,x0,y0,x+1,y,paths);
    dfs(matrix,x0,y0,x-1,y,paths);
    dfs(matrix,x0,y0,x,y+1,paths);
    dfs(matrix,x0,y0,x,y-1,paths);
}
#endif
#if 0
int solve(vector<vector<int>>& matrix) {
    if(matrix[0].empty())return 0;
    set<vector<vector<int>>> paths;
    for(int i=0;i<matrix.size()-1;i++)
    {
        for(int j=0;j<matrix[0].size()-1;j++)
        {
            if(matrix[i][j]==1)
            {
                
                matrix[i][j]==0;//sea
                dfs(matrix,i,j,i,j,paths);
               
               
            }
        }
    }
    return paths.size();
}
#endif
int main()
{
    vector<vector<int> > matrix {
                                    vector<int>{1,1,0,1,1,},
                                    vector<int>{1,0,1,0,0,},
                                    vector<int>{0,1,0,0,1,},
                                    vector<int>{1,1,0,1,0,},
                                    vector<int>{1,1,0,1,1},
                                };
                cout<<"maze:"<<solve(matrix);

            
        
    return 0;
}