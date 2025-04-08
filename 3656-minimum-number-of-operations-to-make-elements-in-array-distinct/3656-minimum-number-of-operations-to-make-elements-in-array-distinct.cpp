class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        int n = nums.size();

        while (true) {
            unordered_set<int> seen;
            bool hasDuplicate = false;

            for (int i = 0; i < n; ++i) {
                if (seen.count(nums[i])) {
                    hasDuplicate = true;
                    break;
                }
                seen.insert(nums[i]);
            }

            if (!hasDuplicate) break;

            // Remove first 3 elements or all if less than 3
            int removeCount = min(3, n);
            nums.erase(nums.begin(), nums.begin() + removeCount);
            n -= removeCount;
            operations++;
        }

        return operations;
    }
};