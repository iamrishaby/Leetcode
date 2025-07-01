class Solution {
public:
    int possibleStringCount(string word) {
        int totalVariations = 1;  // The baseline (only the full string)
        int n = word.size();
        
        vector<int> segmentLengths;  // To store lengths of each repeated character segment
        
        // Step 1: Identify the segments and their lengths
        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (i + 1 < n && word[i] == word[i + 1]) {
                count++;
                i++;
            }
            segmentLengths.push_back(count);
        }
        
        // Step 2: Calculate possible variations by allowing only one segment to vary
        totalVariations = 1;  // Start with just the full string variation
        for (int length : segmentLengths) {
            totalVariations += length - 1;  // Add variations for one segment at a time
        }

        return totalVariations;
    }
};
