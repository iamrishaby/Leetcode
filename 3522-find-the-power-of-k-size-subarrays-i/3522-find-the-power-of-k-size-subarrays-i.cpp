class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        std::vector<int> results;
        int n = nums.size();
        
        for (int i = 0; i <= n - k; ++i) {
            std::vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
            bool isConsecutiveAndSorted = true;
            
            for (int j = 1; j < k; ++j) {
                if (subarray[j] != subarray[j - 1] + 1) {
                    isConsecutiveAndSorted = false;
                    break;
                }
            }
            
            if (isConsecutiveAndSorted) {
                results.push_back(*std::max_element(subarray.begin(), subarray.end()));
            } else {
                results.push_back(-1);
            }
        }
        
        return results;
    }
};