#include <iostream>
using namespace std;
void pre(char* t,int i)
{
    if(t[i]!='#'){
    cout<<t[i]<<" ";
    pre(t,i*2);
    pre(t,i*2+1);
    }
   
   
}
void in_order(char* t,int i)
{
    
    if(t[i]!='#'){
    in_order(t,i*2);
    cout<<t[i]<<" ";
    in_order(t,i*2+1);
    }
  
   
}
void post_order(char* t,int i)
{
    
    if(t[i]!='#'){
    post_order(t,i*2);
    post_order(t,i*2+1);
    cout<<t[i]<<" ";
    }
 
}

int main()
{
  
    int x;
    cin>>x;
    while(x)
    {
        int n=50;
        char* t= new char[n];
        for(int i=0;i<n;i++)
        {
            t[i]='#';
        }
        int i=1;
        while(1)
        {
            cin>>t[i];
            char ch=cin.get();
            if(ch=='\n')
            {
                break;
            }
            i++;
        }
        pre(t,1);
        cout<<endl;
        in_order(t,1);
        cout<<endl;
        post_order(t,1);
        x--;
        cout<<endl;
    }
   
    return 0;
}