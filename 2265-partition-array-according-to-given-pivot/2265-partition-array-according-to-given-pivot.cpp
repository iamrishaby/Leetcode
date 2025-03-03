class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> l, g, e;
        for(int num : nums){
            if(num < pivot){
                l.push_back(num);
            }
            else if(num == pivot){
                e.push_back(num);
            }
            else{
                g.push_back(num);
            }
        }

        vector<int> result;
        result.reserve(nums.size());
        
        result.insert(result.end(), l.begin(), l.end());
        result.insert(result.end(), e.begin(), e.end());
        result.insert(result.end(), g.begin(), g.end());

        return result;

    }
};