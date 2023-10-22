#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> cache;
    
    int dfs(vector<int>& nums, int i) {
        cout<<"i: "<<i<<" ";
        if (i < 0) {
            return 0;
        }
        if (cache[i] != -1) {
            return cache[i];
        }
        
        int res = max(dfs(nums, i - 1), dfs(nums, i - 2) + nums[i]);
        cache[i] = res;
        cout<<endl;
        return res;
        
    }
    
    int rob(vector<int>& nums) {
        cache = vector<int>(nums.size(), -1);
        return dfs(nums, nums.size() - 1);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 1};
    int result = solution.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;
    
    return 0;
}
