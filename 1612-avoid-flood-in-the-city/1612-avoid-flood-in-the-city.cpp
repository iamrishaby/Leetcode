class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> full; // lake -> last full day
        set<int> dryDays;             // days available to dry
        vector<int> ans(n, 1);        // default dry day output (1 is arbitrary)

        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
            if (lake > 0) {
                ans[i] = -1; // raining day
                if (full.count(lake)) {
                    auto it = dryDays.upper_bound(full[lake]);
                    if (it == dryDays.end()) return {}; // no dry day available
                    ans[*it] = lake;   // dry this lake on that dry day
                    dryDays.erase(it); // remove used dry day
                }
                full[lake] = i; // mark lake as full
            } else {
                dryDays.insert(i); // record dry day
            }
        }
        return ans;
    }
};