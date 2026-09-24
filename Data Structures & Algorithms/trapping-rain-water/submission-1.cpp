/**
 * using constant space 
 approach -- two pointer 
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        int i = 0, j = n-1;  // two pointers
        int left_max = 0, right_max = 0;

        int total_water_trap = 0;
        while (i < j) {
            if (height[i] < height[j]) {  // means process the left side
                if (height[i] > left_max) left_max = height[i];
                else total_water_trap += left_max - height[i];
                i++;
            } else { // means process the right side
                if (height[j] >= right_max) right_max = height[j];
                else total_water_trap += right_max - height[j];
                j--;
            }
        }

        return total_water_trap;
    }
};
