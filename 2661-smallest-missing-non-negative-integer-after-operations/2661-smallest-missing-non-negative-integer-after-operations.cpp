class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> cnt(value, 0);
        for (long long a : nums) {
            int r = int(((a % value) + value) % value);
            cnt[r]++;
        }
        int mex = 0;
        while (true) {
            int r = mex % value;
            if (cnt[r] > 0) {
                cnt[r]--;
                ++mex;
            } else {
                return mex;
            }
        }
    }
};