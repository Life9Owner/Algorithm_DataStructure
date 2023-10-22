#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode* root, int depth, vector<int>& ans) {
        if (root == nullptr) return;

        if (depth == ans.size()) {
            ans.push_back(root->val);
        }

        // Increment the depth once per level
        // dfs(root->right, depth + 1, ans);
        // dfs(root->left, depth + 1, ans);
         dfs(root->right,++depth , ans);
        dfs(root->left, ++depth , ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int depth = 0;
        dfs(root, depth, ans);
        return ans;
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}