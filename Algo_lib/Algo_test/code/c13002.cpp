// 13002. 大数相加取模 - 分治
// 计算x*10^y % n, x in [0, 9], y in [0, 1000]
// 法则：(x * y) % n = ((x % n) * (y % n)) % n
#include<iostream>
using namespace std;
long long superMod(int x, int y, int n) {   // 相乘结果可能较大，所以必须用long long
    //the default choice.when the recursive function  goes out.
    if (x == 0) return 0;
    if (y == 0) return x % n;
    if (y == 1) return (x * 10) % n;
    //the repeat the function.//so as we do in loop// I can change it into the while to save the space.
    if (y % 2 == 0) {
        return (superMod(x, y / 2, n))%n;//* superMod(1, y / 2, n)) % n;
        //why is 1
    } else {
        return (superMod(x, y / 2, n))%n;//* superMod(1, y / 2 + 1, n)) % n;
    }
}

int solve(string a, string b, int n)
{
    long result = 0;    // 过程相加可能超出int范围，所以必须至少用long
    // 法则：(x + y) % n = ((x % n) + (y % n)) % n
    for (int i = 0; i < a.length(); i++) {  // 计算a % n
        int x = a[i] - '0';//the first bit of 'a' string  changes into  a decimal number
        int temp = superMod(x, a.length()-i-1, n);
        result = (result + temp) % n;
    }
    for (int i = 0; i < b.length(); i++) {  // 计算 + b % n
        int x = b[i] - '0';
        int temp = superMod(x, b.length()-i-1, n);
        result = (result + temp) % n;
    }
    return result;
}
int solve1(string a,string b,int n)
{
    int ans1=0,ans2=0;
    for(int i=0;i<a.size();i++)
    {
        ans1=((ans1*10+a[i]-'0')%n);
    }
    for(int i=0;i<b.size();i++)
    {
        ans2=((ans2*10+b[i]-'0')%n);
    }
    return (ans1+ans2)%n;
}
int main()
{
    
    cout<<"tea's: "<<solve("122142323","123421323",19)<<endl;
    cout<<"myans :"<<solve1("122142323","123421323",19)<<endl;
    cout<<"tea's: "<<solve("3","2",19)<<endl;
    cout<<"myans :"<<solve1("3","2",19);
    
    return 0;
}
