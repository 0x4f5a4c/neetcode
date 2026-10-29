// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
// Question Link : https://neetcode.io/problems/find-the-punishment-number-of-an-integer/question

#include <bits/stdc++.h>
using namespace std;

/**
 * more optimize code
 */

class Solution {
public:
    bool check(int square, int curr_sum, int num) {
        if (square == 0) return curr_sum == num;
        if (curr_sum > num) return false;

        int d = 10;
        while (square >= d / 10) {
            if (check(square / d, (square % d) + curr_sum, num)) {
                return true;
            }
            if (d > square) break; // Avoid integer overflow for d
            d *= 10;
        }
        return false;
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