#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool isPalindrome(int x) {
        // this may be slow
        string s = to_string(x);

        int i = 0;
        int mid = (s.size() + 1) / 2;
        while (i < mid) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
            i++;
        }
        return true;
    }
};