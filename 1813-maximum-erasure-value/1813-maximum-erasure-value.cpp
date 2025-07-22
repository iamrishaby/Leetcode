class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, right = 0;
        int maxSum = 0, currentSum = 0;

        while (right < nums.size()) {
            if (seen.find(nums[right]) == seen.end()) {
                seen.insert(nums[right]);
                currentSum += nums[right];
                maxSum = max(maxSum, currentSum);
                right++;
            } else {
                seen.erase(nums[left]);
                currentSum -= nums[left];
                left++;
            }
        }

        return maxSum;
    }
};