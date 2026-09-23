// رَبِّ زِدْنِي عِwhile لْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

/**
 * Question :
 *  
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and 
 * nums[i] + nums[j] + nums[k] == 0.
 * 
 * Note : that the solution set must not contain duplicate triplets.
 * 
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * 
 * Explanation: 
 * 
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not matter.
 */


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            int n1 = nums[i];
            int target = -n1;
            // edge cases
            if (i > 0 && nums[i] == nums[i-1]) continue;  // also check the duplicates for the fixing element 
            int j = i + 1, k = n-1;
            while (j < k) {
                int curr_sum = nums[j] + nums[k];
                if (curr_sum > target) {
                    k--;
                } else if (curr_sum < target) j++;
                else {
                    // means both are same here 
                    // but first check the duplicasy
                    while (j < k && nums[j] == nums[j+1]) j++;
                    while (j < k && nums[k] == nums[k-1]) k--;

                    // and then form the answer
                    ans.push_back({-target, nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }

        return ans;
    }
};

