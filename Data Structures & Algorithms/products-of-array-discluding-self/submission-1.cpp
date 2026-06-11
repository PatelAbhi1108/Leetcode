#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Create a result vector initialized with 1s
        vector<int> res(n, 1);

        // Step 2: Compute prefix product for each index
        // This loop fills res[i] with the product of all elements to the left of nums[i]
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        
        // Step 3: Compute postfix product while updating res
        // This loop multiplies res[i] with the product of all elements to the right of nums[i]
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix;  // Multiply current result by postfix (right-side product)
            postfix *= nums[i]; // Update postfix to include nums[i] for next iteration
        }
        
        // Step 4: Return the final result
        return res;
    }
};
