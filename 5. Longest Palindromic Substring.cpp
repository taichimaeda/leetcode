#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        int m = 0;
        int ml = 0, mr = 0;

        // find palindrome of even length
        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i + 1;
            if (r >= s.size() || s[l] != s[r]) {
                continue;
            }
            while (0 <= l && r < s.size() && s[l] == s[r]) {
                l--; r++;
            }
            l++; r--;
            if (r - l + 1 > m) {
                m = r - l + 1;
                ml = l; mr = r;
            }
        }

        // find palindrome of odd length
        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while (0 <= l && r < s.size() && s[l] == s[r]) {
                l--; r++;
            }
            l++; r--;
            if (r - l + 1 > m) {
                m = r - l + 1;
                ml = l; mr = r;
            }
        }

        stringstream ss{};
        for (int j = ml; j <= mr; j++) {
            ss << s[j];
        }
        return ss.str();
    }
};