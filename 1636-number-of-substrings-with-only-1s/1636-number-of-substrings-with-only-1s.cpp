class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1000000007LL;
        long long ans = 0;
        long long cur = 0; // number of consecutive '1's ending at current index
        for (char c : s) {
            if (c == '1') {
                cur = (cur + 1) % MOD;
                ans = (ans + cur) % MOD;
            } else {
                cur = 0;
            }
        }
        return (int)ans;
    }
};