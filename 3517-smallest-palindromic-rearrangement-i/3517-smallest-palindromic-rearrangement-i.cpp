class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};

        // Count frequency
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string left = "";
        char middle = '\0';

        // Build left half in sorted order
        for (int i = 0; i < 26; i++) {
            left += string(freq[i] / 2, 'a' + i);

            if (freq[i] % 2 == 1) {
                middle = 'a' + i;
            }
        }

        // Right half = reverse of left half
        string right = left;
        reverse(right.begin(), right.end());

        if (middle != '\0')
            return left + middle + right;

        return left + right;
    }
};