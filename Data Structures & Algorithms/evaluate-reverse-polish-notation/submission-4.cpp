class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int first, second,ans = 0;
        
        for (int i = 0; i< tokens.size(); i++){

        string ch = tokens[i];
    

        // if we get any operation

        if(ch == "+" || ch == "-" || ch == "/" || ch == "*"){

           if(!st.empty()){
             first = st.top();
             st.pop();
           }
           

            // two numbers in stack

            if(!st.empty()){
                second = st.top();
                st.pop();
            }

            if(ch == "+"){
                ans = first + second;
                st.push(ans);
            }

             if(ch == "-"){
                ans = second - first ;
                st.push(ans);
            }
             if(ch == "*"){
                ans = first * second;
                st.push(ans);
            }
             if(ch == "/"){
                ans = second / first ;
                st.push(ans);
            }


        }

        
        // if we get number 
        else{
            int val = stoi(ch);
            st.push(val);
            ans = val;
        }




        }
        return ans;



    }
};
