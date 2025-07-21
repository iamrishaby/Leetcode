class Solution {
public:
    string makeFancyString(string s) {
        string result;

    for (char c : s) {
        int n = result.size();
        if (n >= 2 && result[n - 1] == result[n - 2] && result[n - 1] == c) {
            continue; // Skip character if it makes 3 in a row
        }
        result += c;
    }

    return result;
        
    }
};