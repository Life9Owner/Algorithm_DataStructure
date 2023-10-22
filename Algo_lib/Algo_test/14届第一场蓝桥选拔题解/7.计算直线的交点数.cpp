#include <iostream>
#include <string.h>
using namespace std;
 
int main()
{
    int M;      //直线的数目
    cin >> M;
    int r, c;   //行列下标
    int point[M+1][M*(M-1)/2+1];
    memset(point, 0, sizeof(point));
    /**<
        行下标r代表直线数目，列下标c代表交点数目，
        而point[r][c]的值（0，1）则代表交点数是否存在
    */
    
    // 自底向上：初始化
    for(r=0; r<M+1; r++)
        point[r][0] = 1;                    //对任意的r,当所有的直线互相平行时，c==0;
    for(r=2; r<M+1; r++)    // 直线数目>=2时，最多交点个数为任意两条直线都相交
    {
        c = r*(r-1)/2;
        point[r][c] = 1;
    }

    // 自底向上：状态转移递推
    int m, n;                               //直线数目m，平行直线数目n（n=1, 2, 3......m）;
    for(m=2; m<M+1; m++)
        for(n=m-1; n>=2; n--)               //交点数sum = n*(m-n) + (m-n)条直线的交点数（状态转移方程）;
        {
           int  n_part = m-n;   // 子问题
           for(c=0; c<=n_part*(n_part-1)/2; c++)
           {
               if(point[n_part][c] == 1)    // n_part条直线存在交点数为c
                    point[m][n*n_part+c] = 1;   // 利用状态转移方程推算
           }
        }
 
    for(c=0; c<=M*(M-1)/2; c++)         // M*(M-1)/2 表示最大下标数
    {
        if(point[M][c])
            cout << c << ' ';
    }
 
    return 0;
}