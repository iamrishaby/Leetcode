class Solution {
public:
    int maxScore(string s) {
    int totalOnes = 0;
    int maxScore = 0;
    int zerosLeft = 0;
    int onesRight = 0;

    for (char c : s) {
        if (c == '1') totalOnes++;
    }

    
    for (int i = 0; i < s.size() - 1; i++) { 
        if (s[i] == '0') zerosLeft++;
        if (s[i] == '1') totalOnes--;

        
        int currentScore = zerosLeft + totalOnes;
        maxScore = max(maxScore, currentScore);
    }

    return maxScore;
    }
};