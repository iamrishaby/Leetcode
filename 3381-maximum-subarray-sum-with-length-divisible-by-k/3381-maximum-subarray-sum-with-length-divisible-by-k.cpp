class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        vector<long long> minPref(k, LLONG_MAX);
        minPref[0] = 0;   // prefix index 0

        long long ans = LLONG_MIN;

        for (int j = 1; j <= n; j++) {
            int mod = j % k;

            if (minPref[mod] != LLONG_MAX)
                ans = max(ans, prefix[j] - minPref[mod]);

            minPref[mod] = min(minPref[mod], prefix[j]);
        }

        return ans;
    }
};