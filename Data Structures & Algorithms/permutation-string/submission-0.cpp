class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // approach 1
        int len = s1.size();
        sort(s1.begin(), s1.end());
        for (int i = 0; i < s2.size(); ++i) {
            string sub_str = s2.substr(i, len);
            sort(sub_str.begin(), sub_str.end());
            if (sub_str == s1) return true;
        }

        return false;
    }
};
