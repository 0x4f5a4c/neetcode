class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;

        while (i <= j) {
            int curr_sum = nums[i] + nums[j];
            if (curr_sum > target) j--;
            else if (curr_sum < target) i++;
            else if (curr_sum == target) return {i+1, j+1};
        }

        return {};
    }
};
