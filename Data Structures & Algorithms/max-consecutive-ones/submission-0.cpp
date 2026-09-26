class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max_ones = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) count++;
            else {
                max_ones = max(max_ones, count);
                count = 0;
            }
        }

        return max(max_ones, count);
    }
};