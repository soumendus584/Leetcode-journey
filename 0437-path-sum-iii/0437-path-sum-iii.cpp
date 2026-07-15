class Solution {
public:
    unordered_map<long long, int> prefix;
    
    int dfs(TreeNode* root, long long currSum, int targetSum) {
        if (root == nullptr)
            return 0;

        currSum += root->val;

        int count = 0;

        // Number of paths ending at current node with sum = targetSum
        if (prefix.count(currSum - targetSum))
            count += prefix[currSum - targetSum];

        // Add current prefix sum
        prefix[currSum]++;

        // Traverse left and right
        count += dfs(root->left, currSum, targetSum);
        count += dfs(root->right, currSum, targetSum);

        // Backtrack
        prefix[currSum]--;

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;   // Base case
        return dfs(root, 0, targetSum);
    }
};