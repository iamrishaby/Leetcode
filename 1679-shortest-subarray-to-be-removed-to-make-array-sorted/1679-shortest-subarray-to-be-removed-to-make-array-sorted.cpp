class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        int left = 0;
    while (left + 1 < n && arr[left] <= arr[left + 1]) {
        left++;
    }
    
    // If the entire array is sorted, no need to remove anything
    if (left == n - 1) {
        return 0;
    }
    
    // Step 2: Find the right sorted portion
    int right = n - 1;
    while (right > 0 && arr[right - 1] <= arr[right]) {
        right--;
    }
    
    // Step 3: Calculate the minimum removal
    int minLength = min(n - left - 1, right); // Remove everything to the right or left
    
    // Step 4: Try merging left and right portions
    int i = 0, j = right;
    while (i <= left && j < n) {
        if (arr[i] <= arr[j]) {
            minLength = min(minLength, j - i - 1);
            i++;
        } else {
            j++;
        }
    }
    
    return minLength;

    }
};