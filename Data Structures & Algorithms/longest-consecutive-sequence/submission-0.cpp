class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Step 1: Insert all numbers into an unordered_set to allow quick lookups (O(1) time complexity)
        unordered_set<int> numSet(nums.begin(), nums.end()); 
        int res = 0; // Variable to store the maximum length of a consecutive sequence

        // Step 2: Iterate over each number in the input array
        for (int num : nums) {
            // Check if 'num' is the start of a sequence (i.e., num - 1 is NOT in the set)
            // This ensures that we only start counting from the smallest number in a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currNum = num;  // Start tracking the consecutive sequence from 'num'
                int streak = 1;      // Initialize the length of the current sequence to 1

                // Step 3: Expand the sequence by checking if 'currNum + 1' exists in the set
                while (numSet.find(currNum + 1) != numSet.end()) {
                    currNum++;  // Move to the next consecutive number
                    streak++;   // Increase the streak length
                }

                // Step 4: Update the maximum sequence length found so far
                res = max(res, streak);
            }
        }
        return res; // Return the length of the longest consecutive sequence found
    }
};
