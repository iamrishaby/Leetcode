#include <vector>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> filtered;
        filtered.push_back(nums[0]);

        // Step 1: Remove consecutive duplicates
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                filtered.push_back(nums[i]);
            }
        }

        int count = 0;

        // Step 2: Count hills and valleys
        for (int i = 1; i < filtered.size() - 1; i++) {
            if ((filtered[i] > filtered[i - 1] && filtered[i] > filtered[i + 1]) || 
                (filtered[i] < filtered[i - 1] && filtered[i] < filtered[i + 1])) {
                count++;
            }
        }

        return count;
    }
};
