// 13004. 矩阵中最大的正方形的边长 - 动态规划
#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int>> &matrix)
{
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }
    int maxSide = 0;
    int rows = matrix.size(), columns = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(columns)); // 初始化为0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;   // 以(i,j)为右下角的正方形边长最大值
                } else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide;
}
int main()
{
    
    vector<vector<int> > matrix {
                                    vector<int>{1,0,1,0,0},
                                    vector<int>{1,0,1,1,1},
                                    vector<int>{1,1,1,1,1},
                                    vector<int>{1,0,0,1,0},
                                };
              cout<<"max length of the square: "<<solve(matrix);
              return 0;
}