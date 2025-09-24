class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // If numerator is 0, answer is "0"
        if (numerator == 0) return "0";

        string result;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) result += "-";

        // Convert to long long to handle overflow cases like INT_MIN
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // Integer part
        result += to_string(n / d);
        long long remainder = n % d;

        // If perfectly divisible, return result
        if (remainder == 0) return result;

        result += ".";  // Add decimal point

        // Map to store remainder -> position in result string
        unordered_map<long long, int> remainderPos;

        while (remainder != 0) {
            // If we've seen this remainder before -> cycle detected
            if (remainderPos.count(remainder)) {
                result.insert(remainderPos[remainder], "(");
                result += ")";
                break;
            }

            // Store remainder position
            remainderPos[remainder] = result.size();

            remainder *= 10;
            result += to_string(remainder / d);
            remainder %= d;
        }

        return result;
    }
};
