#include <stack>

class Solution {
public:
    bool isValid(std::string s) {

        std::stack<char> st;
        char ch;
        
        for (int i = 0; i < s.length(); i++) {
            ch = s[i];
            if (ch == '[' || ch == '{' || ch == '(') {
                st.push(ch);
            } 
            else {
                if (st.empty()) {
                    return false; // If stack is empty and we find a closing bracket, it's invalid
                }
                if ((ch == ')' && st.top() == '(') ||
                    (ch == ']' && st.top() == '[') ||
                    (ch == '}' && st.top() == '{')) {
                    st.pop();
                } else {
                    return false; // Mismatched bracket
                }
            }
        }

        return st.empty(); // If stack is empty, the string is valid
    }
};
