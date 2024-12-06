class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(begin(banned), end(banned));
        int sum = 0;
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (st.find(i) == st.end() && sum + i <= maxSum) {
                sum += i;
                count++;
            }
        }
        return count; // count is always valid as it tracks the numbers selected
    }
};
