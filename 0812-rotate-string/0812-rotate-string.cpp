class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int g = goal.size();

        if(n != g){
            return false;
        }
        
        for(int i = 1; i <= g; i++){
            rotate(s.begin(), s.begin()+1, s.end());
            if(s == goal) return true;
        }

        return false;

    }
};