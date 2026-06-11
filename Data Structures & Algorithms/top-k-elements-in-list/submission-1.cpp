#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;

        // Step 1: Count the frequency of each element
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }

        // Step 2: Min Heap to store k most frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto it = umap.begin(); it != umap.end(); it++) {
            pq.push(make_pair(it->second, it->first)); // (frequency, number)
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Step 3: Extract elements from the heap
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
