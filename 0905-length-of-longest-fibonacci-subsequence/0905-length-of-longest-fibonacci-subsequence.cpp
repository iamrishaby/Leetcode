class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> index;  // Maps value to index
    unordered_map<int, int> dp;  // Key: (i, j) -> value: length of sequence
    int maxLen = 0;
    
    // Fill index map for quick lookup
    for (int i = 0; i < n; i++) {
        index[arr[i]] = i;
    }

    // Iterate through all pairs
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < j; i++) {
            int x = arr[j] - arr[i];  // Required previous number
            if (x < arr[i] && index.count(x)) {  // Check if x exists and maintains increasing order
                int k = index[x];  // Get index of x
                int length = dp[k * n + i] + 1;  // Get previous length and extend it
                dp[i * n + j] = length;  // Update dp
                maxLen = max(maxLen, length);
            } else {
                dp[i * n + j] = 2;  // Default length for new pairs
            }
        }
    }

    return (maxLen > 2) ? maxLen : 0;
    }
};