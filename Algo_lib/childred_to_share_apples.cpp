#include <iostream>

using namespace std;

class Solution {
public:
    int distMoney(int money, int children) {
        money -= children;
        if (money < 0) {
            return -1;
        }
      
        if (money % 7 == 0) {
            return money / 7;
        }
        
        int cnt = 0;
        for (int i = 0; i < children; i++) {
            if (money >= 7) {
                money -= 7;
                cnt++;
            }
            if (money == 3 && cnt == children - 1) {
                cnt--;
                break;
            }

            if (cnt == children && money > 0) {
                cnt--;
            }
        }
        return cnt;
    }
};

int main() {
    Solution solution;
    int money = 23;
    int children = 2;
    int result = solution.distMoney(money, children);
    cout << "Result: " << result << endl;

    return 0;
}
