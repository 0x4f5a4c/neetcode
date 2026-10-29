// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
// Question Link : https://neetcode.io/problems/find-the-punishment-number-of-an-integer/question

#include <bits/stdc++.h>
using namespace std;

/**
 * optimize code
 */

class Solution {
   public:
    bool check(int square, int curr_sum, int num) {
        if (square == 0) return curr_sum == num;
        if (curr_sum > num) return false;

        return check(square / 10, (square % 10) + curr_sum, num) ||
               check(square / 100, (square % 100) + curr_sum, num) ||
               check(square / 1000, (square % 1000) + curr_sum, num) ||
               check(square / 10000, (square % 10000) + curr_sum, num);
        ;
    }

    int punishmentNumber(int n) {
        int punishment = 0;
        for (int num = 1; num <= n; ++num) {
            int square = num * num;
            if (check(square, 0, num)) punishment += square;
        }

        return punishment;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();