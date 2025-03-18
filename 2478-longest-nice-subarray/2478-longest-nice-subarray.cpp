class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, usedBits = 0, maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // If there's a conflict, shrink the window from the left
            while ((usedBits & nums[right]) != 0) {
                usedBits ^= nums[left]; // Remove nums[left] from usedBits
                left++;
            }

            // Include nums[right] in the subarray
            usedBits |= nums[right];

            // Update max length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};