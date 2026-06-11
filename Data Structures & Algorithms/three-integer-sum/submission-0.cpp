class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>>res;
        sort(nums.begin(),nums.end());

        

        for(int i = 0; i < nums.size();i++){

            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            int j = i+1;
            int k = nums.size()-1;

            while(j < k){
                int total = nums[i] + nums [j] + nums [k];

                // total is grater
                if(total > 0){
                    k--;
                }

                // total is smaller
                else if(total < 0){
                    j++;
                }

                // total is equal
                else{
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;

                    // after increasing this J we have to check a condition 
                    // we have to keep on increasing J till we get different value of new J to avoid duplicate output
                    while(nums[j] == nums[j-1] && j<k){
                        j++;
                    }


                }
            }
        }
        return res;
    }
};
