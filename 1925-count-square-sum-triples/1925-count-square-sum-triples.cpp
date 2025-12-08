class Solution {
public:
    int countTriples(int n) {
        int count = 0;

        // Precompute squares for fast lookup
        vector<int> sq(n + 1);
        for (int i = 1; i <= n; i++) sq[i] = i * i;

        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int sum = sq[a] + sq[b];
                int c = sqrt(sum);
                if (c <= n && c * c == sum) {
                    count++;
                }
            }
        }

        return count;
    }
};