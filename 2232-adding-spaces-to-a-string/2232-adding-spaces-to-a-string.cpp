class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int spc_idx = 0;

        std::ostringstream result;

        for(int i = 0; i < s.size(); i++){
            if(spc_idx < spaces.size() && i == spaces[spc_idx]){
                result << " ";
                spc_idx++;

            }

            result << s[i];

        }
        return result.str();
    }
};