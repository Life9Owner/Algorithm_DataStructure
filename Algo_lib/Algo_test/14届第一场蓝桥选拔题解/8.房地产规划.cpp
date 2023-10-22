#include <stdio.h>
#include <stdlib.h>
int count, N, k, vis[11];
long a[11];
void dfs(int n, int num) //传的是已经选入桌上的人的个数和前一个入座的人的编号;
{
    int i, j;
    if (n == N)
    {
        if (abs(a[1] - a[num]) <= k) //因为是圆桌所以最后一个要和第一个再比一次;
        {
            count++;
        }
        return;
    }
    else
    {
        for (i = 1; i <= N; i++)
        {
            if (!vis[i] && abs(a[num] - a[i]) <= k)
            {
                vis[i] = 1;
                dfs(n + 1, i);
                vis[i] = 0;
            }
        }
    }
}

int main()
{
    int i;
    scanf("%d%d", &N, &k);
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &a[i]);
    }
    vis[1] = 1;
    dfs(1, 1); //固定让第一个人最在第一个;
    printf("%d\n", count);
    return 0;
}