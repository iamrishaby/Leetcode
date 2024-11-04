class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0; // This is the position to write the compressed result in-place

        for (int i = 0; i < n;) {
            char ch = chars[i];
            int count = 0;
            
            // Count occurrences of the current character
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // Write the character
            chars[index++] = ch;

            // Write the count if it's more than 1
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[index++] = c;
                }
            }
        }
        
        return index; 
    }
};
