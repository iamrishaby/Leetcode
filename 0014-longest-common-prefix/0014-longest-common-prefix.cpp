class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        if(strs.empty()) return "";

        string prefix = strs[0];
        for(int i = 0; i<n; i++){
            while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) return "";  // No common prefix
            }
        }


        return prefix;

    }
};