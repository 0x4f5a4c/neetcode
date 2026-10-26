// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/n-queens/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool is_valid(vector<string> board, int row, int col, int n) {
        for (int i = row-1; i >= 0; --i) {
            if (board[i][col] == 'Q') return false;
        }

        for (int i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = row-1, j = col+1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int row, int n, vector<string> &board, vector<vector<string>> &ans) {
        if (row >= n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            // now check the cell we are trying to place is valid or not
            if (is_valid(board, row, col, n)) {
                // means this is valid
                board[row][col] = 'Q';
                solve(row+1, n, board, ans);
                board[row][col] = '.';  // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, n, board, ans);
        return ans;
    }
};
