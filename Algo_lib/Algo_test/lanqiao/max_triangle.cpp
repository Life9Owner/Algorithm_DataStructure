#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int tri[200][200];
   int m;
  cin>>m;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<i+1;j++)
    {
      cin>>tri[i][j];
    }
  }
  for(int i=m-2;i>=0;i--)
  {
    for(int j=0;j<i+1;j++)
    {
      tri[i][j]=max(tri[i+1][j],tri[i+1][j+1])+tri[i][j];

    }
  }
  cout<<tri[0][0];
  return 0;
}