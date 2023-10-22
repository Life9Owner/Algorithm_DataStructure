#include<iostream>
#include<string>
#define Max(a,b) ((a)>(b))?(a):(b)
using namespace std;
string A,B;
int L[100][100];
int main(){
    int n,m;
    int i,j;
    cin>>A>>B;//读取字符串uj
    n=A.length();//计算长度
    m=B.length();
    for(i=0;i<=n;i++){//初始化j=0的情况
        L[i][0]=0;
    }
    for(j=0;j<=m;j++){//初始化i=0的情况
        L[0][j]=0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(A[i-1]==B[j-1])
                L[i][j]=L[i-1][j-1]+1;
            else
                L[i][j]=Max(L[i][j-1],L[i-1][j]);
        }
    }
    cout<<L[n][m]<<endl;
    return 0;
}