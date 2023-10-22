#include<iostream>
using namespace std;
int main()
{
  int x1;
  int x3;
  int remain;
  for( x1=1;x1<100;x1++)
  {
     remain=x1+(2*x1)*10;
     x3=(200-remain)%5;
     cout<<x1<<" "<<x1*2<<" "<<x3<<endl;
    if(x3==0)
    {
      break;
    }
  }
    
    cout<<"x1 "<<x1<<"x2 "<<x1*2<<" x3 "<<x3<<endl;
  cout<< "res=" <<x1+x1*10+(200-remain)/5;
  return 0;
}