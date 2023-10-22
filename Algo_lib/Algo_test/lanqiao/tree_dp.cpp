#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> robTree(TreeNode* cur) {
        if (cur == nullptr) {
            return vector<int>{0, 0};
        }
        
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        
        int val1 = max(left[0], left[1]) + max(right[0], right[1]);
        int val2 = cur->val + left[0] + right[0];
        
        return {val1, val2};
    }
    
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
};

// Test the code
int main() {
    // Create a tree for testing
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    // Create an instance of the Solution class
    Solution s;
    
    // Call the rob function with the root of the tree
    int result = s.rob(root);

    // Output the result
    cout << "The maximum amount that can be robbed is: " << result << endl;

    // Cleanup the tree memory
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
