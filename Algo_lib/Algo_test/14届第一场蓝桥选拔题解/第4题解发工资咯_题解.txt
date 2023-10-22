#include<iostream>
using namespace std;
int Dno[6]={100,50,10,5,2,1};//面额大小 
int sum(int x){
    int y=0,res=0;
    while(x>0){
        res+=x/Dno[y];//当前面额的最多张数
        x%=Dno[y++];//减去已计算的面额总值，并将面额减小
    }
    return res;
} 
int main(){
    int n;
    while(cin>>n&&n){
        int m,tot=0;
        for(int i=0;i<n;i++){
            cin>>m;
            tot+=sum(m);
        }
        cout<<tot<<endl;
    }
    return 0;
}