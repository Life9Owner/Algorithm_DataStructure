#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
nj            int pivot = low + (high - low) / 2;
            if(nums[pivot] ==nums[high])
            {
                return nums[pivot];
            }
            if (nums[pivot] < nums[high]) {
                high = pivot-1;
            }
            else if (nums[pivot] > nums[high]) {
                low = pivot + 1;
            }
            
           
        }
        return nums[low];
    }
};

int main() {
    // Test the function
    vector<int> nums = {3,4,5,1,2};//{4, 5, 6, 7, 0, 1, 2};
    Solution sol;
    int minNum = sol.findMin(nums);
    std::cout<<"min"<<minNum;
    return 0;
}
