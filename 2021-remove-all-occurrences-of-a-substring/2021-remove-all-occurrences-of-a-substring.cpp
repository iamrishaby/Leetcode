class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) {  // While 'part' exists in 's'
        s.erase(s.find(part), part.length());  // Erase the first occurrence
    }
    return s;
    }
};