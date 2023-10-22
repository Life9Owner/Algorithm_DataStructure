 #include <iostream>
using namespace std;
int climbStairs(int n);
int main()
{ 
 cout<<climbStairs(10)<<"steps by recurrence.";
 return 0;
}

int climbStairs(int n) {
if (n < 1){
    return 0;
}
if (n == 1){
    return 1;
}
if (n == 2){
    return 2;
}
return climbStairs(n - 1) + climbStairs(n - 2);
}

