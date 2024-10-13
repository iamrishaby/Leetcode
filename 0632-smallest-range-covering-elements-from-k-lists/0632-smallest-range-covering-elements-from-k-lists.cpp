class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        //{element, listidx, idx} 
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int maxel = INT_MIN;
        for(int i = 0; i<k; i++){
            pq.push({nums[i][0], i, 0});
            maxel = max(maxel, nums[i][0]);
        }

        vector<int> resultRange = {-1000000, 1000000};

        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();

            int minel = curr[0];
            int listidx = curr[1];
            int idx = curr[2];

            if(maxel - minel < resultRange[1] - resultRange[0]){
                resultRange[0] = minel;
                resultRange[1] = maxel;
            }

            //decrease the range from min idx
            if(idx+1 < nums[listidx].size()){
                int nextel = nums[listidx][idx+1];
                pq.push({nextel, listidx, idx+1});
                maxel = max(maxel, nextel);
            }else{
                break;
            }

        }

        return resultRange;




    }
};