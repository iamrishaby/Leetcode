class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int prefixSum = nums[0];

        for(int i = 1; i < n; i++){
            if (nums[i] == nums[i - 1] + 1) {
            prefixSum += nums[i];  // Add to prefix sum if sequential
            } else {
            break;  // Stop when the sequence breaks
            }
        }
        unordered_set<int> numSet(nums.begin(), nums.end());
        int x = prefixSum;
        while (numSet.find(x) != numSet.end()) {
        x++;  // Increment x until we find a missing number
        }

        return x;
    }
};