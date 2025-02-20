class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
    unordered_set<string> existing(nums.begin(), nums.end());

    for (int i = 0; i < (1 << n); i++) { // Iterate from 0 to 2^n - 1
        string candidate = "";
        for (int j = n - 1; j >= 0; j--) {
            candidate += ((i >> j) & 1) ? '1' : '0'; // Convert number to binary string
        }
        if (existing.find(candidate) == existing.end()) {
            return candidate; // Return the first missing binary string
        }
    }
    return ""; // This should never be reached
}
    
};