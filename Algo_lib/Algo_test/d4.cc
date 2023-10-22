#include <iostream>
#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot - 1;
            }
            else if (nums[pivot] > nums[high]) {
                low = pivot + 1;
            }
            else {
                return nums[pivot];
            }
        }
        // return nums[high];
        return -1;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {3,4,5,1,2}; // Modify this array as needed for testing.
    int minVal = solution.findMin(nums);
    std::cout << "Minimum value: " << minVal << std::endl;
    return 0;
}
