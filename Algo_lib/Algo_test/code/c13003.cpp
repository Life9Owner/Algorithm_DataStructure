// 13003. 矩阵中第k小的数 - 二分
/*
1  3  5  7  9 11
2  4  6  8 10 12
3  5  7  9 11 13
4  6  8 10 12 14
5  7  9 11 13 15
6  8 10 12 14 16
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 检查第k小的数是否在left-mid区间内
int sorted(vector<vector<int>> &matrix,int k)
{
    int n=matrix.size();
    vector<int> temp(n*n);
    int x=0;
    for(int i=0;i<matrix[0].size();i++)
   {
    for(int j=0;j<matrix.size();j++)
    {
       
        temp[x]=matrix[i][j];
         x++;
    }
   }
    sort(temp.begin(),temp.end());
    return temp[k-1];
}

bool check(vector<vector<int>> &matrix, int mid, int k)
{
    //n is the row number.
    // int i = n - 1;//from the first column and the last row
    
    int i=matrix.size()-1;
    int j = 0;
    int num = 0;    // <=mid的元素个数
    while (i >= 0 && j < matrix.size()) {
        if (matrix[i][j] <= mid) {
            num += i + 1;
            j++;
        } else {
            i--;
        }
    }
    return num >= k;
}

int solve(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    int left = matrix[0][0];
    int right = matrix[n - 1][n - 1];
    while (left < right) {  // 二分查找
    //use the while loop instead of recursion
        int mid = left + ((right - left) / 2);
        if (check(matrix, mid, k)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
    //or return right-1
}
int main()
{
    
    vector<vector<int> > matrix {
                                    vector<int>{1 , 3 , 5,  7  ,9 ,11},
                                    vector<int>{2 , 4 , 6 , 8, 10, 12},
                                    vector<int>{3  ,5 , 7,  9, 11 ,13},
                                    vector<int>{4 , 6 , 8 ,10 ,12, 14},
                                    vector<int>{5,  7,  9 ,11, 13, 15},
                                    vector<int>{6,  8 ,10, 12 ,14 ,16}
                                };

        for(int i=1;i<=36;i++)
         {
        //     cout<<"answer1:  "<<sorted(matrix,i)<<"    ";
        //     cout<<"answer2:  "<<solve(matrix,i)<<endl;
            if(sorted(matrix,i)==solve(matrix,i))cout<<"True";
        }
        
    return 0;
}