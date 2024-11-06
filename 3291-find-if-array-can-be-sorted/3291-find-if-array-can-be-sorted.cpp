class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        
        // Perform bubble sort with the set bit condition
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                // Check if adjacent elements have the same number of set bits
                if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1])) {
                    // If they do and are out of order, swap them
                    if (nums[j] > nums[j + 1]) {
                        std::swap(nums[j], nums[j + 1]);
                    }
                }
            }
        }
        
        // Check if the array is sorted
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        
        return true;
    }
};