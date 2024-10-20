class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(auto n : nums){
            freq[n]++;
        }

        for(const auto& pair : freq){
            if(pair.second > 1){
                return true;
            } 
        }

        return false;
    }
};