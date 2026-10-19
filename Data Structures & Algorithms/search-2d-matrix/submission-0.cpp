class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // brute force
        for (auto arr : matrix) {
            for (int x : arr)
                if (x == target)
                    return true;
        }

        return false;
    }
};
