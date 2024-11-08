class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
    int totalXOR = 0;
    vector<int> answer;
    
    // Compute the initial XOR of all elements in the array
    for (int num : nums) {
        totalXOR ^= num;
    }
    
    // Perform the queries
    for (int i = n - 1; i >= 0; i--) {
        // The value of k that maximizes the XOR result
        int k = totalXOR ^ ((1 << maximumBit) - 1);
        answer.push_back(k);
        
        // Remove the last element for the next query
        totalXOR ^= nums[i];
    }
    
    // Since the queries were processed in reverse order, we need to reverse the answer
    //reverse(answer.begin(), answer.end());
    
    return answer;
    }
};