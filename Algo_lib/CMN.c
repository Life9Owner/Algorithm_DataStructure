#include<stdio.h>
int Cnm(int n,int m)
{
    // C(n,m)=n!/((n-m)!*m!)（m≤n）
    int ans=jiecheng(n)/(jiecheng(n-m)*jiecheng(m));
    return ans;
}
int A(n,m)
{
    int ans=jiecheng(n)/jiecheng(n-m);
}
int jiecheng(int n)
{
    if(n==0)return 1;
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=i;
    }
    return ans;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    printf("A(n,m)=%d\n",A(n,m));
    printf("C(n,m)=%d",Cnm(n,m));
    return 0;
}