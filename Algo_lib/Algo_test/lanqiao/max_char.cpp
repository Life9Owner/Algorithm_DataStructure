#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  string str;
  cin>>str;
  int max=0,cnt=0;
  char max_c;//保存max字符
  for(int i=0;i<str.size();i++)
  {
    for(int j=0;j<str.size();j++)
    {
      if(str[i]==str[j])
      {
        cnt++;
      }
      if(cnt>=max)
      {
        max_c=str[i];
        max=cnt;
      }
      
    }
    cnt=0;
  }
  cout<<max_c<<endl;
  cout<<max;
  return 0;
}
