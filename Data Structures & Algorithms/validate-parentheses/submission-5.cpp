class Solution {
public:
    bool isValid(string s) {
       char ch;
        stack<char>st;
        st.push(s[0]);

        for(int i=1; i<s.length(); i++){
            ch=s[i];
            

            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }

            else{
                if(st.empty()){
                    return false;
                }
                if(ch==')' && st.top() =='(' ||
            ch == ']' && st.top() == '[' ||
            ch == '}' && st.top() == '{'){
                st.pop();
            }
            else{
                return false;
                }
            }

        }
        return st.empty();
    }
};
