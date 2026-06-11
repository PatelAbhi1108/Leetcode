class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        

        //creating vector array to store car values in pair form
        vector<pair<int,int>> cars;

        //iterate on position array and pushing value in vector
        for(int i = 0; i< position.size(); i++){
            cars.push_back({position[i] , speed[i]});
        }

        // after inserting all the values , sort the array
        sort(cars.begin(),cars.end(),greater<pair<int,int>>());
        // greater<pair<int,int>>() is used to do sorting in descending order 
        //over here greater<pair<int,int>>() means this function first compare first value and if its same then it compare second value


        //creating stack 
        stack<double>st;

        for(auto& car : cars){
            int position = car.first;
            int speed = car.second;

            // use (double) for type cast so if answer comes in decimal then it wont lost
            double time = (double)(target-position) / speed;

            if(st.empty() || time > st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};