// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
// Question Link : https://www.geeksforgeeks.org/problems/josephus-problem/1
// Question Link : https://neetcode.io/problems/find-the-winner-of-the-circular-game/question

#include <bits/stdc++.h>
using namespace std;

// using recursion

class Solution {
public:
    int find_idx(int n, int k) {
        if (n == 1) return 0;
        int idx = find_idx(n-1, k);
        idx = (idx + k) % n;
        return idx;
    }

    int findTheWinner(int n, int k) {
        int _idx = find_idx(n, k);
        return _idx+1;
    }
};