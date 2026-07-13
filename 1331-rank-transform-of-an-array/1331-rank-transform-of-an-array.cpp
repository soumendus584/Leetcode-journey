class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> rank;
        int currentRank = 1;

        for (int num : sorted) {
            if (rank.find(num) == rank.end()) {
                rank[num] = currentRank;
                currentRank++;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};