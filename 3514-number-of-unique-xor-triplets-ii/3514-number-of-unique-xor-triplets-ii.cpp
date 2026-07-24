class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()) << 1;

        vector<bool> pairXor(mx, false);

        // All XORs of two numbers
        for (int a : nums) {
            for (int b : nums) {
                pairXor[a ^ b] = true;
            }
        }

        vector<bool> tripletXor(mx, false);

        // XOR each pair XOR with every number
        for (int x = 0; x < mx; x++) {
            if (!pairXor[x]) continue;

            for (int c : nums) {
                tripletXor[x ^ c] = true;
            }
        }

        int ans = 0;
        for (bool x : tripletXor)
            ans += x;

        return ans;
    }
};