#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        if (s.empty()) {
            return 0;
        }

        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        int ans = 0;
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';
            if (sign > 0 && ans > (INT_MAX - sign * digit) / 10) {
                return INT_MAX;
            }
            if (sign < 0 && ans < (INT_MIN - sign * digit) / 10) {
                return INT_MIN;
            }
            ans = ans * 10 + sign * digit;
            i++;
        }
        return ans;
    }
};
