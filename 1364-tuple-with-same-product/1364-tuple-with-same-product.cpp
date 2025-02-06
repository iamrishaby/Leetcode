class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productMap;
    int n = nums.size();
    int result = 0;

    // Calculate all product pairs and store in map
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int product = nums[i] * nums[j];
            productMap[product]++;
        }
    }

    // Count valid tuples
    for (auto& [product, count] : productMap) {
        if (count > 1) {
            result += (count * (count - 1) / 2) * 8;
        }
    }

    return result;
    }
};