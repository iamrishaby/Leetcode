class Solution {


    private:
    bool isNoZero(int x) {
        while (x > 0) {
            if (x % 10 == 0) return false; // digit contains 0
            x /= 10;
        }
        return true;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (isNoZero(a) && isNoZero(b)) {
                return {a, b};
            }
        }
        return {};
    }
};