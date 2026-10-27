// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
// Question Link : https://www.geeksforgeeks.org/problems/josephus-problem/1
// Question Link : https://neetcode.io/problems/find-the-winner-of-the-circular-game/question

// using array 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> nums;
        int i = 0;
        for (int i = 1; i <= n; ++i) nums.push_back(i);
        while (nums.size() > 1) {
            int idx = (i + k - 1) % nums.size();
            nums.erase(nums.begin() + idx);
            i = idx;
        }
        return nums[0];
    }
};
