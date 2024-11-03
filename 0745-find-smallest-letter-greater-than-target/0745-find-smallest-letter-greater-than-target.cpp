class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        for(char ch : letters){
            if((ch - target) > 0){
                return ch;
            }
        }
        return letters[0];
    }
};