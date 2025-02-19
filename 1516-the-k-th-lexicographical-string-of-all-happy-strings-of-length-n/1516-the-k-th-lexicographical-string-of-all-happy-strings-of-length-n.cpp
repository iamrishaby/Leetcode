class Solution {
public:

    void generateHappyStrings(int n, string current, char lastChar, vector<string>& result) {
        if (current.length() == n) {
            result.push_back(current);
            return;
        }
        
        for (char ch : {'a', 'b', 'c'}) {
            if (ch != lastChar) {  // Ensure no adjacent characters are the same
                generateHappyStrings(n, current + ch, ch, result);
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        generateHappyStrings(n, "", '\0', happyStrings);
        
        return (k <= happyStrings.size()) ? happyStrings[k - 1] : "";
    }
};