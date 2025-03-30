class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;
    
    // Step 1: Store the last occurrence of each character
    for (int i = 0; i < s.size(); i++) {
        lastIndex[s[i]] = i;
    }

    vector<int> result;
    int start = 0, end = 0;
    
    // Step 2: Traverse the string and create partitions
    for (int i = 0; i < s.size(); i++) {
        end = max(end, lastIndex[s[i]]); // Update the farthest reach
        if (i == end) {  // Partition found
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }

    return result;
    }
};