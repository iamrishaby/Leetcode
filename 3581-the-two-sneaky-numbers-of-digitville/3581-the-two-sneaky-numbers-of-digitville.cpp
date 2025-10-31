class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = (int)nums.size() - 2;         // original range is 0..n-1
    vector<int> count(n, 0);
    vector<int> result;
    result.reserve(2);

    for (int x : nums) {
        if (count[x] == 1)                // we've seen x before -> it's a duplicate
            result.push_back(x);
        count[x]++;
        if (result.size() == 2) break;   // we found both sneaky numbers
    }
    return result;
    }
};