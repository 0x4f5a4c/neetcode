class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        // brute force solution
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; ++i) {
            mpp[nums[i]]++;
        }

        for (auto &[val, count] : mpp) {
            if (count > 1) return val;
        }
        return -1;
    }
};
