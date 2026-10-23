class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int n : nums) {
            if (seen[n] > 0)
                return true;
            seen[n]++;
        }

        return false;
    }
};