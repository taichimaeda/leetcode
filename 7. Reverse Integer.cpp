#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int reverse(int x) {
        if (-10 < x && x < 10) {
            return x;
        }

        queue<int> digits{};
        while (x != 0) {
            // C++ rounds towards zero
            digits.push(x % 10);
            x /= 10;
        }

        int ans = 0;
        while (!digits.empty()) {
            int digit = digits.front(); digits.pop();
            if (digit > 0 && ans > (INT_MAX - digit) / 10) {
                return 0;
            }
            if (digit < 0 && ans < (INT_MIN - digit) / 10) {
                return 0;
            }
            ans = ans * 10 + digit;
        }
        return ans;
    }
};
