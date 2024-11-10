class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, maxFreq = 0, maxlen = 0;
        vector<int> count(26, 0);  // Frequency count for characters A-Z

        for (int r = 0; r < n; ++r) {
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);

            // If the current window size minus the max frequency character count
            // is greater than k, we need to shrink the window
            if ((r - l + 1) - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
            }

            // Calculate the maximum length of the window
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
