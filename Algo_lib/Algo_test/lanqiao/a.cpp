#include<set>
#include<vector>
using namespace std;
  void dfs(vector<vector<int> >&matrix,int x0,int y0,int x,int y,vector<vector<int> >&path)
{
	path.push_back({x-x0,y-y0});
    //int xy[4][2]={{0,1},{0,-1},{1,0},{1,-1}};
  	int dx[4]={0,0,1,-1};
	int dy[4]={1,-1,0,0};
    for(int k=0;k<4;k++)
    {
    	//int loc_x=x+xy[k][1];
        //int loc_y=y+xy[k][1];
        int loc_x=x+dx[k];
        int loc_y=y+dy[k];
        if(loc_x>=0&&loc_x<matrix.size()&&loc_y>=0&&loc_y<matrix[0].size()&&matrix[loc_x][loc_y]==1)
        {	
        	matrix[loc_x][loc_y]=1;
       		 dfs(matrix,x,y,loc_x,loc_y,path);
        }
   }
         
}


int solve(vector<vector<int> >&matrix)
{
  set<vector<vector<int>> >paths;
	for(int i=0;i<matrix.size();i++)
    {
    	for(int j=0;j<matrix[0].size();j++)
		{
        	if(matrix[i][j]==1)
            {
              matrix[i][j]=0;
              vector<vector<int> >path;
              dfs(matrix,i,j,i,j,path);
              paths.insert(path);
            }
        }
    }
  return paths.size();
}
            	
            
  