class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0, max_len = 0;
        vector<int> seen(256, -1);

        while (r < n) {
            if (seen[s[r]] != -1) {
                if (seen[s[r]] >= l) l = seen[s[r]] + 1;
            }

            max_len = max(max_len, r - l +1);
            seen[s[r]] = r;
            r++;
        }
        return max_len; 
    }
};