#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int num=0,max=0;
    
    for(int i=0;i<s.length();i++){
        int count=1;
        for(int j=i+1;j<s.length();j++){
                if(s[j]==s[i]) count++;
            }
        if(count>max||(count==max&&s[i]<s[num])){
            max=count;
            num=i;
        }
    }
    cout<<s[num]<<endl<<max;
    return 0;
}