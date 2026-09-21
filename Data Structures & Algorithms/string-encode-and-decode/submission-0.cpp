// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // one solution approach
    string encode(vector<string>& strs) {
        string encoded_string = "";
        for (auto &str : strs) {
            for (char &ch : str) {
                encoded_string.push_back(ch);
            }
            encoded_string.push_back((char)0xFFFFFF);  // a random string 
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_string;
        string curr = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == (char)0xFFFFFF) {
                decoded_string.push_back(curr);
                curr = "";
            } else {
                curr.push_back(s[i]);
            }
        }

        return decoded_string;
    }
};
