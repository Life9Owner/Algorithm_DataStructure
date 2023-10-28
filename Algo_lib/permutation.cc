#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> visited;
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(vector<int>& nums) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                temp.push_back(nums[i]);
                dfs(nums);
                temp.pop_back();
                visited[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        visited.resize(nums.size(), 0);
        dfs(nums);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = solution.permute(nums);

    // Printing the generated permutations for debugging
    for (const vector<int>& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
