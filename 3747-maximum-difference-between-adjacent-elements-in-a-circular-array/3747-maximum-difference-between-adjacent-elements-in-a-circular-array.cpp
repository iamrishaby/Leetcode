class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
    int n = nums.size();
    int maxDiff = 0;

    for (int i = 0; i < n; ++i) {
        int next = (i + 1) % n;
        int diff = std::abs(nums[i] - nums[next]);
        maxDiff = std::max(maxDiff, diff);
    }

    return maxDiff;
    }
};