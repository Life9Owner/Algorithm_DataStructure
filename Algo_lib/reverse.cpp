#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
int main()
{
    int num;
    cin>>num;
    stack<int> stk;
    while(num)
    {
        stk.push(num%10);
        num/=10;
    }
    int ans=0;
    int i=0;
    while(!stk.empty())
    {
        ans=ans*10+stk.top();
        i++;
        stk.pop();
    }
    printf("%d",ans);
    
    return 0;
}