class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
    for (int num = low; num <= high; ++num) {
        std::string s = std::to_string(num);
        int len = s.size();
        
        // Skip numbers with odd number of digits
        if (len % 2 != 0) continue;
        
        int half = len / 2;
        int sum1 = 0, sum2 = 0;
        
        // Calculate sum of first and second halves
        for (int i = 0; i < half; ++i) {
            sum1 += s[i] - '0';
            sum2 += s[i + half] - '0';
        }
        
        if (sum1 == sum2) {
            ++count;
        }
    }
    return count;
    }
};