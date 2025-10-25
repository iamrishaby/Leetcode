class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        
        // Correct money from complete weeks:
        // sum_{k=0..weeks-1} (28 + 7*k) = 28*weeks + 7 * (weeks*(weeks-1)/2)
        int total = 28 * weeks + 7 * (weeks * (weeks - 1) / 2);
        
        // Money from remaining days (partial week starting with Monday = weeks + 1)
        int start = weeks + 1;
        for (int i = 0; i < days; ++i) {
            total += start + i;
        }
        
        return total;
    }
};