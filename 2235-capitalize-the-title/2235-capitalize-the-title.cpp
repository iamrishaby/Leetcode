class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();
        for (int i = 0; i < n; ) {
            int start = i;
            // Move `i` to the end of the current word
            while (i < n && title[i] != ' ') {
                i++;
            }
            int wordLength = i - start;
            
            // Convert entire word to lowercase
            for (int j = start; j < i; j++) {
                title[j] = tolower(title[j]);
            }
            
            // Capitalize first letter if word length is more than 2
            if (wordLength > 2) {
                title[start] = toupper(title[start]);
            }
            
            // Move `i` to the start of the next word
            i++;
        }
        
        return title;
    }
};