// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
// Question Link : https://www.geeksforgeeks.org/problems/josephus-problem/1
// Question Link : https://neetcode.io/problems/find-the-winner-of-the-circular-game/question

#include <bits/stdc++.h>
using namespace std;

// using constant space
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 2; i <= n; ++i) ans = (ans + k) % i;
        return ans + 1;
    }
};
