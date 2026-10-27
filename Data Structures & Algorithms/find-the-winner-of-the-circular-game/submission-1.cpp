// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
// Question Link : https://www.geeksforgeeks.org/problems/josephus-problem/1
// Question Link : https://neetcode.io/problems/find-the-winner-of-the-circular-game/question

#include <bits/stdc++.h>
using namespace std;

// using queue
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) q.push(i);

        while (q.size() > 1) {
            for (int count = 1; count <= k-1; ++count) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }

        return q.front();
    }
};
