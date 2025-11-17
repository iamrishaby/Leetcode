class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -k - 1;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == 1) {
                if (i - last <= k) return false; // need at least k zeros => distance >= k+1
                last = i;
            }
        }
        return true;
    }
};