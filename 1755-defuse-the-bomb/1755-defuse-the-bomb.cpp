class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
    vector<int> result(n, 0);
    
    if (k == 0) {
        // If k is 0, all numbers are replaced with 0
        return result;
    }

    // Precompute the sum of the array twice (circular sum simulation)
    vector<int> extended(code.begin(), code.end());
    extended.insert(extended.end(), code.begin(), code.end());

    int start, end;
    if (k > 0) {
        start = 1;            // Start from the next element
        end = k;              // Up to k elements ahead
    } else {
        start = n + k;        // k is negative, start goes backward
        end = n - 1;          // End at the last index of the previous circle
    }

    // Sliding window sum in the circular array
    int currentSum = 0;
    for (int i = start; i <= end; ++i) {
        currentSum += extended[i];
    }

    for (int i = 0; i < n; ++i) {
        result[i] = currentSum;
        // Slide the window
        currentSum -= extended[start++];
        currentSum += extended[++end];
    }

    return result;
    }
};