class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // Helper function to check feasibility of a given penalty
        auto isFeasible = [&](int penalty) {
            int operations = 0;
            for (int balls : nums) {
                if (balls > penalty) {
                    operations += (balls - 1) / penalty; // Calculate required operations
                }
            }
            return operations <= maxOperations;
        };

        int left = 1;                       // Minimum possible penalty
        int right = *max_element(nums.begin(), nums.end()); // Maximum possible penalty
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2; // Midpoint for binary search
            if (isFeasible(mid)) {
                result = mid; // Update result if feasible
                right = mid - 1; // Try for smaller penalties
            } else {
                left = mid + 1; // Increase penalty if not feasible
            }
        }

        return result; // Minimum penalty found
    }
};
