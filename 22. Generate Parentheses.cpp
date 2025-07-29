#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        if (n == 1) {
            return {"()"};
        }

        int m = n * 2;
        int power = 1;
        for (int i = m; i > 0; i--) {
            power *= 2;
        }

        vector<string> ans{};
        for (int bits = 0; bits < power; bits++) {
            int height = 0;
            array<char, 100> curr{};

            bool ok = true;
            for (int i = 0; i < m; i++) {
                if ((bits >> i) & 1) {
                    curr[i] = '(';
                    height++;
                } else {
                    curr[i] = ')';
                    height--;
                }
                if (height < 0) {
                    ok = false;
                }
            }
            curr[m] = '\0';

            if (ok && height == 0) {
                ans.emplace_back(curr.data());
            }
        }
        return ans;
    }
};