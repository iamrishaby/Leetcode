class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));



        int maxstreak = 0;
        for(int &num : nums){
            int streak = 0;
            long long curr = num;

            while(st.find(curr)!= st.end()){
                streak++;

                if(curr*curr > 1e5){
                    break;
                }

                curr = curr*curr;

            }
            maxstreak = max(maxstreak, streak);
        }

        return maxstreak < 2 ? -1 : maxstreak;
    }
};