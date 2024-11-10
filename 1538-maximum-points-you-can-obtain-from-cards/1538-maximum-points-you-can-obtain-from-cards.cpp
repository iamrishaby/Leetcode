class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();

        int lsum =0, rsum = 0, maxsum = 0;

        for(int i = 0 ; i < k; i++){
            lsum = lsum + arr[i];
        }
        maxsum = lsum;

        int ridx = n-1;
        for(int i = k-1; i >=0 ; i--){
            lsum = lsum - arr[i];
            rsum = rsum + arr[ridx];
            ridx = ridx-1;
            maxsum = max(lsum+rsum, maxsum);
        }
        return maxsum;
    }
};