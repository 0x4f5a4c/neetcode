class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size()-1;
        int ans = INT_MIN;

        while (i < j) {
            int h = min(heights[i], heights[j]);
            int w = j - i;
            int area = h * w;
            ans = max(ans, area);
            if (heights[i] < heights[j]) i++;
            else j--; 
        }

        return ans;
    }
};
