class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        for (int x : nums) if (x == 1) ++cnt1;
        if (cnt1 > 0) {
            // Each non-1 needs one operation with some adjacent 1
            return n - cnt1;
        }
        // No ones initially: find shortest subarray with gcd == 1
        int bestLen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int g = 0;
            for (int j = i; j < n; ++j) {
                g = std::gcd(g, nums[j]);
                if (g == 1) {
                    bestLen = min(bestLen, j - i + 1);
                    break; // no need to extend j further from this i
                }
            }
        }
        if (bestLen == INT_MAX) return -1;
        // Need (bestLen - 1) ops to create a 1, then (n - 1) to spread it
        return (bestLen - 1) + (n - 1);
    }
};