// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<int> &nums, int goal) {
        if (goal < 0) return 0;
        int sum = 0, l = 0, n = nums.size(), count = 0;
        for (int r = 0; r < n; ++r) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            count += r - l + 1;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};
