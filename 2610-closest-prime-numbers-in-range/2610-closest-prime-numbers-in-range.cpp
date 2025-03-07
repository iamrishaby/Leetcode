class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> is_prime(right + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= right; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= right; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Step 2: Collect prime numbers in the given range
    vector<int> primes;
    for (int i = left; i <= right; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    // Step 3: Find the closest pair of prime numbers
    if (primes.size() < 2) {
        return {-1, -1}; // No valid pair exists
    }

    int min_diff = INT_MAX;
    vector<int> result(2);

    for (size_t i = 1; i < primes.size(); i++) {
        int diff = primes[i] - primes[i - 1];
        if (diff < min_diff) {
            min_diff = diff;
            result = {primes[i - 1], primes[i]};
        }
    }

    return result;
    }
};