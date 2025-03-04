class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for (char c : s) {
            if (!isdigit(c)) {
                st.push(c);
            } else if (!st.empty()) {
                st.pop();
            }
        }
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};