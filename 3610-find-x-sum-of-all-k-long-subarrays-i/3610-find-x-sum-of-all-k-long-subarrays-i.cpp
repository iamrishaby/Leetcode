class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
    vector<int> result;

    for (int i = 0; i <= n - k; ++i) {
        unordered_map<int, int> freq;
        // Count frequency of elements in the current subarray
        for (int j = i; j < i + k; ++j) {
            freq[nums[j]]++;
        }

        // Store elements and their frequencies in a vector
        vector<pair<int,int>> freqVec;
        for (auto &p : freq) {
            freqVec.push_back({p.first, p.second}); // {element, frequency}
        }

        // Sort by frequency descending, and by element descending if frequency ties
        sort(freqVec.begin(), freqVec.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first > b.first;
        });

        // Take top x elements and calculate their sum in the subarray
        int sum = 0;
        int count = 0;
        for (auto &p : freqVec) {
            if (count >= x) break;
            // Add p.second occurrences of p.first
            sum += p.first * p.second;
            count++;
        }

        result.push_back(sum);
    }

    return result;
    }
};