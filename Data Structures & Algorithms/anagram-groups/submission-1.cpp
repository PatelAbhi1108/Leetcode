class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>res;

        //here this is the for loop to iterate through each string in the input vector
        for (int i = 0; i < strs.size(); i++){
            string s = strs[i];
            vector <int> count(26,0);
            
            // here is the sub for loop to count the frequency of each character
            for(int j = 0; j<s.length();j++){
                char c = s[j];
                count[c-'a']++;
            }

            //construction of the key using character counts 
            string key = to_string(count[0]);
            for(int k =1;k<26;k++){
                key+=","+ to_string(count[k]);
            }

            res[key].push_back(s);
        }

        vector<vector<string>>result;
        for(unordered_map<string,vector<string>>::iterator it=res.begin();it!=res.end();it++){
            result.push_back(it->second);
        }
        return result;

    }
};
