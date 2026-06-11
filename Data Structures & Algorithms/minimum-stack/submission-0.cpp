#include <bits/stdc++.h>

class MinStack {
public:
stack<int> st;
stack<int> minSt;


    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || minSt.top() >= val){
            minSt.push(val);
        }
    }
    
    void pop() {
        if(!st.empty()){
            
            if(minSt.top() == st.top()){
                minSt.pop();
            }
            st.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
        return st.top();
        }
        throw runtime_error("Stack is empty");
    }
    
    int getMin() {
       
      
    if (!minSt.empty()) return minSt.top();
    throw runtime_error("Min stack is empty");
}
        
    
};
