#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int N,V;//amount,capacity
  int w[N],v[N];
  cin>>N>>V;
  for(int i=0;i<N;i++)
  {
    cin>>w[i];//weitht
    cin>>v[i];//value
  }
  int value_tag=0,weigh_tag=0,max_val=0;
  int visited[N]={0};
  for(int i=0;i<N;i++)
  {
    value_tag=0;
     weigh_tag=0;
    for(int j=0;j<N;j++)
    {
        if(weigh_tag==V)
      {
        weigh_tag+=w[j];
        value_tag+=v[j];
      }
    }
    if(value_tag>max_val)
    {
      max_val=value_tag;   
    }
     
  }
  cout<<"out PUT"<<max_val;

  return 0;
}