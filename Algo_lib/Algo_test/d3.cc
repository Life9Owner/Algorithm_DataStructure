#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        for (int i = 0; i < n - 2; i += 2) {
            cout << "come here" << endl;
            if (nums[i] != nums[i + 1]) return nums[i];
        }
        return nums[nums.size() - 1];
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> nums = {1,1,2}; // Modify this array as needed
    int result = solution.singleNonDuplicate(nums);
    cout << "Single non-duplicate element: " << result << endl;
    return 0;
}
