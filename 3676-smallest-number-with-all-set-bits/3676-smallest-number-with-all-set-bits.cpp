class Solution {
public:
    int smallestNumber(int n) {
        int bitCount = 0;
        int temp = n;
        while (temp > 0) {
            bitCount++;
            temp >>= 1;
        }

        int result = (1 << bitCount) - 1;
        
        if (result < n) {
            result = (1 << (bitCount + 1)) - 1;
        }
        
        return result;   
    }
};