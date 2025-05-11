#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string intToRoman(int num) {
        string s = format("{:04}", num); // cheating?
        stringstream ss{};

        auto helper = [&](int digit, string four, string nine, string five, string one) {
            if (digit == 4) {
                ss << four;
                return;
            }
            if (digit == 9) {
                ss << nine;
                return;
            }
            if (digit >= 5) {
                ss << five;
                digit -= 5;
            }
            for (; digit > 0; digit--) ss << one;
        };

        assert(s[0] - '0' <= 3); // 0 <= num < 3999
        helper(s[0] - '0', "", "", "", "M");
        helper(s[1] - '0', "CD", "CM", "D", "C");
        helper(s[2] - '0', "XL", "XC", "L", "X");
        helper(s[3] - '0', "IV", "IX", "V", "I");

        return ss.str();
    }
};
