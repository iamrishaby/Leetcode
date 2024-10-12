class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        // Iterate through each number in nums
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int minVal = INT_MAX; // Initialize to the maximum possible integer
            bool found = false;

            // Iterate through each bit (up to 30 bits, as num <= 10^9)
            for (int bit = 0; bit <= 30; bit++) {
                // Check if the current bit is set (i.e., it's 1)
                if ((num >> bit) & 1) {
                    // Create candidate by unsetting the current bit
                    int cand = num & ~(1 << bit);

                    // Ensure candidate is non-negative
                    if (cand < 0) continue;

                    // Check if the condition holds: cand | (cand + 1) == num
                    if ((cand | (cand + 1)) == num) {
                        if (cand < minVal) {
                            minVal = cand;
                            found = true;
                        }
                    }
                }
            }

            // If a valid candidate is found, use it; otherwise, set result to -1
            res[i] = found ? minVal : -1;
        }

        return res;
    }
};