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
    string ans = "~";   // Larger than any lowercase string

    void dfs(TreeNode* root, string curr) {
        if (root == NULL)
            return;

        // Add current character at the front
        curr = char(root->val + 'a') + curr;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            if (curr < ans)
                ans = curr;
            return;
        }

        dfs(root->left, curr);
        dfs(root->right, curr);
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};