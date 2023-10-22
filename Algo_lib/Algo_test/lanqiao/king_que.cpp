
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
vector<vector<int>> ans;
bool in_area(const vector<vector<int>>& board,int i,int j)
{
return i>=0&&i<board.size()&&j>=0&&j<board[0].size();
}
void dfs(vector<vector<int>>& board,int i,int j)
{
if(!in_area(board,i,j))return;
if(board[i][j]==-1)return;
if(board[i][j]==2)
{
ans.push_back({i,j});
board[i][j]=-1;//visited;
return ;
}
else if(board[i][j]==0){
if(!in_area(board,i,j))
dfs(board,i-1,j-1);
if(!in_area(board,i,j))
dfs(board,i-1,j);
if(!in_area(board,i,j))
dfs(board,i-1,j+1);
if(!in_area(board,i,j))
dfs(board,i,j+1);
if(!in_area(board,i,j))
dfs(board,i+1,j+1);
if(!in_area(board,i,j))
dfs(board,i+1,j);
if(!in_area(board,i,j))
dfs(board,i+1,j-1);
if(!in_area(board,i,j))
dfs(board,i,j-1);
}

}
vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    set<vector<int>> myset;
    for(int i=0;i<queens.size();i++)
    {
        myset.insert(queens[i]);
    }
    
    vector<vector<int>> board(8,vector<int>(8,0));
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(king[0]==i&&king[1]==j)
            {
                board[i][j]=1;//the king
            }
            vector<int> temp={i,j};
            if(myset.find(temp)!=myset.end())
            {
                board[i][j]=2;//the queue;
            }
        }
    }
    cout<<" -------board"<<endl;
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<" -------board"<<endl;

    dfs(board,king[0],king[1]);
    return ans;
}
};
int main() {
    Solution solution;

    vector<vector<int>> queens = {{0, 1}, {1, 0}, {4, 0}, {0, 4}, {3, 3}, {2, 4}};
    vector<int> king = {0, 0};
    
    vector<vector<int>> result = solution.queensAttacktheKing(queens, king);
    
    cout << "Result:" << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
