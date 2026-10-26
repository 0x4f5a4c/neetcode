// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/n-queens/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // optimize soluiton
    unordered_set<int> cols, left_diag, right_diag;

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
        if (row >= n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            // now check the cell we are trying to place is valid or not
            if (cols.find(col) != cols.end() || left_diag.find(row - col) != left_diag.end() ||
                right_diag.find(row + col) != right_diag.end())
                continue;

            cols.insert(col);
            left_diag.insert(row-col);
            right_diag.insert(row+col);
            board[row][col] = 'Q';

            solve(row+1, n, board, ans);

            cols.erase(col);
            left_diag.erase(row-col);
            right_diag.erase(row+col);
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, n, board, ans);
        return ans;
    }
};
