class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;

        int n = s.size();
        int l = 0, maxlen = 0;

        for(int r = 0; r < n; r++){
            char curr = s[r];

            if(mpp.find(curr) != mpp.end() && mpp[curr] >= l){
                l = mpp[curr] + 1;
            }

            mpp[curr] = r;

            maxlen = max(maxlen, r-l+1);

        }
        return maxlen;
    }
};