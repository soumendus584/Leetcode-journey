class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char ch : word) {
            freq[ch - 'a']++;
        }

        // Most frequent characters first
        sort(freq.rbegin(), freq.rend());

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            int pushes = (i / 8) + 1;
            ans += freq[i] * pushes;
        }

        return ans;
    }
};