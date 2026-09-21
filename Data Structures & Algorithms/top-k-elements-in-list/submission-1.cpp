class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // another approach using min_heap
        unordered_map<int, int> mpp;
        for (int &x : nums) mpp[x]++;

        // now define the PQ
        priority_queue<P, vector<P>, greater<P>> pq;

        for (auto &it : mpp) {
            pq.push({it.second, it.first});
            if (pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
