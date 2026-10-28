// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
// Question Link : https://neetcode.io/problems/k-th-smallest-in-lexicographical-order/question

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count(long curr, long next, int limit) {
        int _count = 0;

        while (curr <= limit) {
            _count += (next - curr);
            curr *= 10;  // next level starting point in the same subtree
            next *= 10;  // next level starting point in the next subtree
            next = min(next, (long)limit + 1);
        }

        return _count;
    }

    int findKthNumber(int n, int k) {
        long curr = 1;
        k -= 1;

        while (k > 0) {
            int _count = count(curr, curr+1, n);
            if (_count <= k) {
                curr++;
                k -= _count;
            } else {
                // means in the same tree go to the next level
                curr *= 10;
                k -= 1;  // because we already counted the current number
            }
        }

        return (int)curr;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();