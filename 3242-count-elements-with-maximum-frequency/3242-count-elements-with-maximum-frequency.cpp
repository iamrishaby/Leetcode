class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int n : nums){
            freq[n]++;
        }

        // Step 2: Find maximum frequency
        int maxFreq = 0;
        for (auto& [num, count] : freq) {
            maxFreq = max(maxFreq, count);
        }

        // Step 3: Sum up all counts that equal maxFreq
        int total = 0;
        for (auto& [num, count] : freq) {
            if (count == maxFreq) {
                total += count;
            }
        }

        return total;

    }
};