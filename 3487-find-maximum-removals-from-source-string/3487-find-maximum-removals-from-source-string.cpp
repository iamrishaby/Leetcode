class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int lenSource = source.length();
        int lenPattern = pattern.length();

        vector<int> minRemovals(lenPattern + 1, INT_MAX);  // DP array initialized to INT_MAX
        vector<bool> isTargetIndex(lenSource, false);       // Boolean array to mark target indices

        minRemovals[0] = 0;  // Base case: 0 characters matched from pattern

        // Mark the target indices in the boolean array
        for (int index : targetIndices) {
            isTargetIndex[index] = true;
        }

        // Iterate over the source string
        for (int i = 0; i < lenSource; i++) {
            // Iterate over the pattern from right to left
            for (int j = lenPattern; j > 0; j--) {
                if (source[i] == pattern[j - 1] && minRemovals[j - 1] != INT_MAX) {
                    minRemovals[j] = min(minRemovals[j], minRemovals[j - 1] + (isTargetIndex[i] ? 1 : 0));
                }
            }
        }

        // If no valid subsequence is found, return targetIndices.size(), otherwise subtract minRemovals[lenPattern]
        return targetIndices.size() - (minRemovals[lenPattern] == INT_MAX ? 0 : minRemovals[lenPattern]);
    }
};