/**
 * brute force solution
 */
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            set<int> st;
            for (int j = i; j < n; ++j) {
                st.insert(fruits[j]);
                if (st.size() <= 2) max_len = max(max_len, j - i + 1);
                else break;
            }
        }

        return max_len;
    }
};