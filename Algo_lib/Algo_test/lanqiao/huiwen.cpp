#include <iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  // 请在此输入您的代码
  #if 0
  vector<int> vec(8);
  for(int i=0;i<8;i++)
  {
    char x;
    x=x-'0';
    vec.push_back(x);
  }
  #endif
  int date;
  cin>>date;
  char str[8], str1[8],str2[8];
  for(int i=date;;i++)
  {
    itoa(date,str,10);
    itoa(date,str1,10);
    reverse(str1,str1+strlen(str1));
    if(str1==str)break;
  }
  cout<<str1<<endl<<str2;
  return 0;
}