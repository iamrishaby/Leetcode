class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int> st;
        long long result = 0;
        long long currsum = 0;

        int l = 0, r = 0;

        while(r < n){

            while(st.count(nums[r])){
                currsum -= nums[l];
                st.erase(nums[l]);
                l++;
            }

            currsum += nums[r];
            st.insert(nums[r]);

            if(r - l + 1 == k){
                result = max(result, currsum);

                currsum -= nums[l];
                st.erase(nums[l]);
                l++;
            }

            r++;
        }

        return result;


    }
};