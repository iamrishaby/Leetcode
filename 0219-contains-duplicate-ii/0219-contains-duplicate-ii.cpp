class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n = nums.size();
        
        map<int, int> mp;
        for(int i=0; i<n; i++) {
			// element already exists
			// check takes O(logn) in a map and O(1) in unordered map 
            if(mp.find(nums[i]) != mp.end()) {
                if(abs(mp[nums[i]] - i) <= k)
                    return true; // condition satisfied
                else
                    mp[nums[i]] = i;
					// just update with latest index for next check.
            }
            
			// adding new element
            else 
				mp[nums[i]] = i; 
        }
        
        return false;
    }
};