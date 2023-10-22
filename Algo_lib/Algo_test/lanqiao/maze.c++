#include<bits/stdc++.h>
using namespace std;
struct point{
    int x;
    int y;
    int pre;//why is int;
};
point pQueen[1000];//队列
int head =0;
int tail=0;
void showPath(int p)
{
    if(p!=-1)
    {
        showPath(pQueen[p].pre);
        printf("(%d,%d)\n",pQueen[p].x,pQueen[p].y);
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    int map[m+2][n+2];//地图
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>map[i][j];
        }
    }
    point startpoint,endpoint;//节点。保存每个点x,y坐标。并存前一个点的下标
    cin>>startpoint.x>>startpoint.y>>endpoint.x>>endpoint.y;//输入起始点和终点
    startpoint.pre=-1;//前一个点的索引无效。设为-1
    pQueen[tail]=startpoint;//往队列中存入头节点
    tail++;
    bool markList[m+2][n+2];//这个二维数组用来记录是否已经被访问
    memset(markList,0,sizeof(markList));
    int fx[4][2]={{-1,0},{0,1},{1,0},{0,-1}};//控制方向用的
    while(head<tail)
    {
        for(int i=0;i<4;i++)
        {
            int dx=pQueen[head].x+fx[i][0];
            int dy=pQueen[head].y+fx[i][1];
            if(map[dx][dy]==0&&markList[dx][dy]==0)
            {
                
               pQueen[tail].x=dx;
               pQueen[tail].y=dy;
               pQueen[tail].pre=head;
               markList[dx][dy]=true;
               tail++;//这里面每添加一个节点，tail指针就要往后移
               if(dx==endpoint.x&&dy==endpoint.y)
               {
                showPath(tail-1);//递归打印，传入point的索引。
               }
            }
        }
        head++;//出队
    }

    return 0;
} // namespace std;

