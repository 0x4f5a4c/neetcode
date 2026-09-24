class Solution {
public:

    void _compute_left_max(vector<int> &arr, vector<int> &heights, int n) {
        arr.resize(n);
        arr[0] = 0;
        for (int i = 1; i < n; ++i) {
            arr[i] = max(arr[i-1], heights[i-1]);
        }
    }

    void _compute_right_max(vector<int> &arr, vector<int> &heights, int n) {
        arr.resize(n);
        arr[n-1] = 0;
        for (int i = n-2; i >= 0; --i) {
            arr[i] = max(arr[i+1], heights[i+1]);
        }
    }

    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        vector<int> left_max, right_max;
        _compute_left_max(left_max, height, n);
        _compute_right_max(right_max, height, n);

        // now calculating the answer
        int curr_trap = 0, total_trap_water = 0;
        for (int i = 0; i < n; ++i) {
            curr_trap = min(left_max[i], right_max[i]) - height[i];
            if (curr_trap > 0) total_trap_water += curr_trap;
        }
        return total_trap_water;
    }
};
