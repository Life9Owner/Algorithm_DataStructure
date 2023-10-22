// 13005. 汉诺塔游戏 - 递归
// 执行操作：借助mid将n个从src挪动到dst
#include<iostream>
#include<vector>
using namespace std;
void move(int a,int b){
    //the answer need a move(,)
}
void hanota(int n, int src, int mid, int dst) {
    if (n == 1) {
        move(src, dst);
        return;
    }
    hanota(n-1, src, dst, mid); // 借助dst将n-1个从src挪动到mid
    move(src, dst);  // 第n个挪到dst
    hanota(n-1, mid, src, dst); // 借助src将n-1个从mid挪动到dst
}

void solve(int n)
{
    hanota(n, 0, 1, 2);
}
int main()
{
    return 0;
}