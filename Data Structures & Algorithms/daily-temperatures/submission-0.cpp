class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int>st;
        vector<int>result(temperatures.size(),0); // initialize whole array with 0

        //iterate the array
        for(int i = 0; i<temperatures.size() ;i++){
            
            //using this while loop we are updating all the previous days value with warmer temp
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int index = st.top();
                st.pop();
                result[index] = i - index;

            }
            
            // pushing index number so we can just update the index value
            st.push(i);
        }
        return result;
    }
};
