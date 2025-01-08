class Solution {
public:

    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        return str2.find(str1) == 0 && str2.rfind(str1) == (str2.length() - str1.length());
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
    int count = 0;

    // Iterate through all pairs (i, j) where i < j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isPrefixAndSuffix(words[i], words[j])) {
                ++count;
            }
        }
    }

    return count;
    }
};