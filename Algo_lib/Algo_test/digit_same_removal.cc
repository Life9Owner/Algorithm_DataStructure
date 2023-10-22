#include <iostream>
using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1, b = 9;
        for(int i = 1; i <= n; i++) {
            ans += b;
            b *= (10 - i);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 3; // Provide the desired input for debugging

    // int result = solution.countNumbersWithUniqueDigits(n);
    // std::cout << "Result: " << result << std::endl;
    if(12&1)
    {
        cout<<"even"<<endl;
    }
    if(11&1)
    {
        cout<<"odd"<<endl;
    }

    return 0;
}
