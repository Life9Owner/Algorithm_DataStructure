#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;//
//MY aim is to find the number of the different islands in the matrix.
// 1 is is land and 0 is water
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
class solution2//using the explict stack to solve the problem
{
    public:
    int solve(vector<vector<int> >&matrix)
    {
        stack<vector<vector<int>>> Stk;
        stack<vector<vector<int>>> paths;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==1)
                {
                    vector<vector<int> >path;
                    path.push_back({i,j});
                    Stk.push(path);
                    // Stk.push({11,1});
                }
            }
        }
    }
};

class solution{
    public:
    void land(vector<vector<int> >&matrix,int x0,int y0,int x,int y,vector<vector<int> >&path)
    {
        path.push_back({x-x0,y-y0});
        for(int k=0;k<4;k++)
        {
            int loc_x=x+dx[k];
            int loc_y=y+dy[k];
            if(loc_x>=0&&loc_y>=0&&loc_x<matrix.size()&&loc_y<matrix[0].size()&&matrix[loc_x][loc_y]==1)
            {
                matrix[loc_x][loc_y]=0;
            land(matrix,x,y,loc_x,loc_y,path);
            }
        }
    }
    int solve(vector<vector<int> >&matrix)
    {
        set<vector<vector<int> > > paths;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==1)
                {
                    vector<vector<int> > path;
                    matrix[i][j]=0;
                    land(matrix,i,j,i,j,path);
                    paths.insert(path);
                }
            }
        }
        return paths.size();
    }
};

int main()
{
    vector<vector<int> >matrix={
                                    vector<int>{1,1,0,1,1,},
                                    vector<int>{1,0,1,0,0,},
                                    vector<int>{0,1,0,0,1,},
                                    vector<int>{1,1,0,1,0,},
                                    vector<int>{1,1,0,1,1},
                                };
    solution a;
                cout<<"island:"<<a.solve(matrix);
    return 0;
}
