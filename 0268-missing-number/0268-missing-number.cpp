class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int xor_result = 0;

    // XOR all elements in the array
    for (int num : nums) {
        xor_result ^= num;
    }

    // XOR the result with numbers from 0 to n
    for (int i = 0; i <= n; ++i) {
        xor_result ^= i;
    }

    return xor_result;
    }
};