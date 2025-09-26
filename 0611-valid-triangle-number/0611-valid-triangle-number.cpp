class Solution {
public:

    // int binarysearch(vector<int>& nums, int l, int r, int target){
    //     int k = -1;


    //     while(l <= r){
    //         int mid = l + (r-l)/2;
    //         if(nums[mid] < target){
    //             k = mid; //valid
    //             l = mid+1;
    //         } else{
    //             r = mid - 1;
    //         }
    //     }
    //     return k;
    // }


    int triangleNumber(vector<int>& nums) {
        int n = nums.size();

        if(n < 3){
            return 0;
        }

        sort(begin(nums), end(nums));
        int count = 0;

        for(int k = n-1; k>=2; k--){
            int i = 0;
            int j = k-1;

            //nums[i] + nums[j] > nums[k]

            while(i < j){
                if(nums[i] + nums[j] > nums[k]){
                    count += (j-i);
                    j--;
                }else{
                    i++;
                }
            }


        }


        return count;
    }
};