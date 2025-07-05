class Solution {
public:
    int findLucky(vector<int>& arr) {
         std::unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : arr) {
            freq[num]++;
        }

        int result = -1;

        // Find the largest lucky number
        for (auto& [num, count] : freq) {
            if (num == count) {
                result = std::max(result, num);
            }
        }

        return result;
    }
};