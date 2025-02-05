class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
        return true;
    }

    std::vector<int> diffIndices;

    // Collect indices where characters differ
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] != s2[i]) {
            diffIndices.push_back(i);
        }
    }

    // If there are not exactly two differences, return false
    if (diffIndices.size() != 2) {
        return false;
    }

    // Check if swapping the mismatched characters makes the strings equal
    int i = diffIndices[0];
    int j = diffIndices[1];

    return (s1[i] == s2[j] && s1[j] == s2[i]);
    }
};