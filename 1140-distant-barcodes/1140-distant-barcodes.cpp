class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> frequency;
        for (int code : barcodes) {
            frequency[code]++;
        }
        
        // Max heap to sort barcodes by frequency
        std::priority_queue<std::pair<int, int>> maxHeap;
        for (const auto& entry : frequency) {
            maxHeap.push({entry.second, entry.first}); // {frequency, barcode}
        }
        
        // Result vector to store the rearranged barcodes
        std::vector<int> result(barcodes.size());
        int index = 0;
        
        // Arrange barcodes in the result array
        while (!maxHeap.empty()) {
            auto [freq, barcode] = maxHeap.top();
            maxHeap.pop();
            
            // Place the barcode freq times in the result array
            for (int i = 0; i < freq; ++i) {
                result[index] = barcode;
                index += 2;
                
                // If index is out of bounds for even places, start filling odd places
                if (index >= barcodes.size()) {
                    index = 1;
                }
            }
        }
        
        return result;
    }
};