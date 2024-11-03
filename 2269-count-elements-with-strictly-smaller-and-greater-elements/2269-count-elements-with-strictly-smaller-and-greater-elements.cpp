class Solution {
public:
    int countElements(vector<int>& nums) {
        int min_val = *std::min_element(nums.begin(), nums.end());
        int max_val = *std::max_element(nums.begin(), nums.end());
        
        // Count the number of elements that are strictly between min_val and max_val
        int count = 0;
        for (int num : nums) {
            if (num > min_val && num < max_val) {
                count++;
            }
        }
        
        return count;
    }
};