class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
    long long N = n * n;
    long long sum_actual = 0, sum_square_actual = 0;
    long long sum_expected = (N * (N + 1)) / 2;
    long long sum_square_expected = (N * (N + 1) * (2 * N + 1)) / 6;
    
    unordered_map<int, int> freq;
    int repeated, missing;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = grid[i][j];
            sum_actual += num;
            sum_square_actual += (long long)num * num;
            freq[num]++;
            if (freq[num] > 1) repeated = num;
        }
    }
    
    long long diff = sum_expected - sum_actual; // b - a
    long long square_diff = sum_square_expected - sum_square_actual; // b^2 - a^2
    long long sum_ab = square_diff / diff; // b + a
    
    missing = (diff + sum_ab) / 2;
    
    return {repeated, missing};
    }
};