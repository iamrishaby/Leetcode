class ProductOfNumbers {
    private:
    std::vector<int> prefixProduct;
public:
    ProductOfNumbers() {
        prefixProduct = {1}; // Initialize with 1 for easy multiplication
    }
    
    void add(int num) {
        if (num == 0) {
            // Reset prefixProduct because any product involving zero is zero
            prefixProduct = {1};
        } else {
            // Append new product to the list
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefixProduct.size();
        if (k >= n) return 0; // A zero has been encountered within the last k elements
        return prefixProduct[n - 1] / prefixProduct[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */