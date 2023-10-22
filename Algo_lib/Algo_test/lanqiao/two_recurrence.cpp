#include<iostream>
using namespace std;
int dfs(int i)
{
    if(i<0)return 0;
    cout<<"i:"<<i<<" ";
    int res=max(dfs(i-1),dfs(i-2)+i);
    return res;
}
int main()
{
    
    cout<<endl<<"res: "<<dfs(5);
    return 0;
}