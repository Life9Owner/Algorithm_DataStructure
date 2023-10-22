#include <iostream>
using namespace std;
//plus from the head is just ok.
int n;
int num[100][100];
int main(void){
  // 请在此输入您的代码
  cin >> n;
  for(int i = 0;i < n;i++)
    for(int j = 0;j<=i;j++)
    cin >> num[i][j];
  for(int i = 1;i<n;i++){
    num[i][0] += num[i-1][0]; 
    for(int j = 1;j < i;j++)
      num[i][j] += max(num[i-1][j] , num[i-1][j-1]);
    num[i][i] += num[i-1][i-1];
  }
  if(n &1 )
  cout << num[n-1][n/2];
  else cout << max(num[n-1][n/2] , num[n-1][n/2-1]);
  return 0;
}