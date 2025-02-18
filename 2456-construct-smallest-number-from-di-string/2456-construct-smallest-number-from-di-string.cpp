class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";
        stack<int> st;
        int num = 1;

    for (int i = 0; i <= pattern.size(); i++) {
        st.push(num++);
        
        // If we reach an 'I' or the end of the string, process the stack
        if (i == pattern.size() || pattern[i] == 'I') {
            while (!st.empty()) {
                result += to_string(st.top());
                st.pop();
            }
        }
    }
    
    return result;
    }
};