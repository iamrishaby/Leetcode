class Solution {
public:
    bool canPartition(string &s, int index, int target) {
    if (index == s.size()) return target == 0;
    
    int num = 0;
    for (int i = index; i < s.size(); i++) {
        num = num * 10 + (s[i] - '0'); // Forming the number from substring
        if (num > target) break; // Prune unnecessary checks
        if (canPartition(s, i + 1, target - num)) return true;
    }
    return false;
}
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
        int square = i * i;
        string sqStr = to_string(square);
        if (canPartition(sqStr, 0, i)) {
            sum += square;
        }
    }
    return sum;
    }
};