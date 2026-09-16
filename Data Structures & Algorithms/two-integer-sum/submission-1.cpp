/**
 * another better approach is to use a hash map to store the indices of the elements we have seen so far. This way, we can check if the complement of the current element (i.e., target - nums[i]) exists in the hash map. If it does, we have found our solution.
 * This approach has a time complexity of O(n) and a space complexity of O(n).
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> num_to_index;
        for (int i = 0; i < n; ++i) {
            int complement = target - nums[i];
            if (num_to_index.find(complement) != num_to_index.end()) 
                return {num_to_index[complement], i};
            num_to_index[nums[i]] = i;
        }
        return {};
    }
};