class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);   // dp[i] = number of people who learn secret on day i
        vector<long long> share(n + 2, 0); // difference array for sharers
        
        dp[1] = 1; // Day 1: one person knows
        share[1 + delay] += 1;   // they will start sharing on day (1+delay)
        if (1 + forget <= n) 
            share[1 + forget] -= 1; // they will stop sharing after forget days
        
        long long currSharers = 0;
        
        for (int day = 2; day <= n; day++) {
            currSharers = (currSharers + share[day]) % MOD; // active sharers today
            dp[day] = currSharers; // these many people learn today
            
            if (dp[day] == 0) continue;
            
            // They start sharing after delay days
            if (day + delay <= n) {
                share[day + delay] = (share[day + delay] + dp[day]) % MOD;
            }
            // They stop sharing after forget days
            if (day + forget <= n) {
                share[day + forget] = (share[day + forget] - dp[day] + MOD) % MOD;
            }
        }
        
        // Sum all people who haven't forgotten by day n
        long long result = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day >= 1) {
                result = (result + dp[day]) % MOD;
            }
        }
        return (int)result;
    }
};