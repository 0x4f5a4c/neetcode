// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @time complexity: O(n)
     * @space complexity: O(n)
     */
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        for (char c : t) {
            if (count.find(c) == count.end()) return false;
            count[c]--;
            if (count[c] < 0) return false;
        }
        return true;
    }
};

/**
 * can we solve this problem with O(1) space complexity?
 * yes, we can sort both strings and compare them.
 */

class Solution {
public:
    /** 
     * @time complexity: O(nlogn)
     * @space complexity: O(1) if we ignore the space used by the sorting algorithm, otherwise O(n) for the sorted strings.
     */
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        sort(s.begin(), s.end());  // takes O(nlogn) time complexity
        sort(t.begin(), t.end());  // takes O(nlogn) time complexity
        return s == t;
    }
};

/**
 * any other approach?
 * yes, we can use a fixed size array of 26 elements to count the frequency of each character in the strings, since we are only dealing with lowercase letters.
 * This will give us O(n) time complexity and O(1) space complexity.
 */

class Solution {
public: 
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        for (char c : t) {
            count[c - 'a']--;
            if (count[c - 'a'] < 0) return false;
        }
        return true;
    }
    /**
     * @time complexity: O(n)
     * @space complexity: O(1)
     */
};
