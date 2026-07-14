class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int idx, int g1, int g2, vector<int>& nums,
              vector<vector<vector<int>>>& dp) {

        if (idx == nums.size()) {
            return (g1 > 0 && g1 == g2) ? 1 : 0;
        }

        if (dp[idx][g1][g2] != -1)
            return dp[idx][g1][g2];

        long long ans = 0;

        // Option 1: Skip current element
        ans += solve(idx + 1, g1, g2, nums, dp);

        // Option 2: Put in first subsequence
        ans += solve(idx + 1,
                     std::gcd(g1, nums[idx]),
                     g2,
                     nums,
                     dp);

        // Option 3: Put in second subsequence
        ans += solve(idx + 1,
                     g1,
                     std::gcd(g2, nums[idx]),
                     nums,
                     dp);

        return dp[idx][g1][g2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<vector<int>>> dp(
            nums.size(),
            vector<vector<int>>(mx + 1,
                vector<int>(mx + 1, -1)));

        return solve(0, 0, 0, nums, dp);
    }
};