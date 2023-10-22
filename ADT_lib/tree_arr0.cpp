#include <iostream>
using namespace std;
void pre(char* t,int i)
{
    // if(t[2*i]=='#'&&t[2*i+1]=='#')
    // return ;
    if(t[i]!='#'){
    cout<<t[i]<<" ";
    // if(t[i*2]!='#')
    pre(t,i*2);
    // if(t[i*2+1]!='#')
    pre(t,i*2+1);
    }
   
}
void in_order(char* t,int i)
{
    // if(t[2*i]=='#'&&t[2*i+1]=='#')
    // return ;
    if(t[i]!='#'){
    
    // if(t[i*2]!='#')
    in_order(t,i*2);
    // if(t[i*2+1]!='#')
    cout<<t[i]<<" ";
    in_order(t,i*2+1);
    }
   
}
void post_order(char* t,int i)
{
    // if(t[2*i]=='#'&&t[2*i+1]=='#')
    // return ;
    if(t[i]!='#'){
    
    // if(t[i*2]!='#')
    post_order(t,i*2);
    // if(t[i*2+1]!='#')
    post_order(t,i*2+1);
    cout<<t[i]<<" ";
    }
   
}

int main()
{
    int n=50;
    // char* t=new int[n];
    char* t= new char[n];
    for(int i=0;i<n;i++)
    {
        t[i]='#';
    }
    int i=1;
    while(1)
    {
        cin>>t[i];
       
        if(t[i]=='$')
        {
            t[i]='#';
            break;
        }
         i++;
    }
    pre(t,1);
    cout<<endl;
    in_order(t,1);
    cout<<endl;
    post_order(t,1);
}