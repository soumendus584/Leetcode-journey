/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {

        if (root == nullptr)
            return;

        // Include current node in path
        path.push_back(root->val);

        // Update remaining target
        targetSum -= root->val;

        // If leaf node and target becomes 0
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            ans.push_back(path);
        }

        // Traverse left and right
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};