#include <iostream>
using namespace std;
#define N 7
char* create_space()
{
    char* p = (char*)malloc(N);
    if (NULL == p)
    {
        printf("p is null\n");
        return NULL;
    }
 
    return p;
}
 
int create_sqtree(char* T, int pos)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '$')
        return 0;
    T[pos] = ch;  //给根节点赋值
    create_sqtree(T, pos * 2 + 1); //创建左子树
    create_sqtree(T, pos * 2 + 2);//创建右子树
 
    return 0;
}
//层次遍历
int show_sqtree(char* T)
{
    printf("层次遍历：");
    int i;
    for (i = 0; i < 7; i++)
    {
        printf("%c ",T[i]);
    }
    printf("\n");
    return 1;
}
//前序遍历
void preOrder(char* T,int pos)
{
    if (pos >= 7)
        return;
    printf("%c ", T[pos]);
    preOrder(T,2*pos+1);
    preOrder(T, 2 * pos + 2);
}
//中序遍历
void inOrder(char* T, int pos)
{
    if (pos >= 7)
        return;
    inOrder(T, 2 * pos + 1);
    printf("%c ", T[pos]);
    inOrder(T, 2 * pos + 2);
}
//后续遍历
void postOrder(char* T, int pos)
{
    if (pos >= 7)
        return;
    postOrder(T, 2 * pos + 1);
    postOrder(T, 2 * pos + 2);
    printf("%c ", T[pos]);
}
int main(int argc, char* argv[])
{
 
    char* T = create_space();
 
    create_sqtree(T, 0);
    show_sqtree(T);
    printf("先序遍历：");
    preOrder(T,0);
    printf("\n");
    printf("中序遍历：");
    inOrder(T,0);
    printf("\n");
    printf("后序遍历：");
    postOrder(T,0);
    printf("\n");
    return 0;
}