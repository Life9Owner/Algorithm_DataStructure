#include<iostream>
using namespace  std;
void dfs(int cnt,int x)
{
    
    if(x>0||cnt<3)
        {
            printf("x: %d ",x);
            
            printf("cnt: %d\n",cnt);
        dfs(++cnt,x-1);
     }
     



     

}
int main(){

   int cnt=99;
    dfs(0,10);
}
