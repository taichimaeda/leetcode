#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) {
        if (!s.empty() && p.empty()) {
            return false;
        }

        // dp[i][j] = true if s[i:] and p[j:] match
        bool dp[s.size() + 1][p.size() + 1];
        for (int i = 0; i < s.size() + 1; i++) 
        for (int j = 0; j < p.size() + 1; j++) {
            dp[i][j] = false;
        }
        dp[s.size()][p.size()] = true;

        // reversed because '*' appears after character
        for (int i = s.size() - 1; i >= 0; i--) {
            int j = p.size() - 1;
            while (j >= 0) {
                if (p[j] != '*') {
                    if (s[i] == p[j] || p[j] == '.') {
                        dp[i][j] |= dp[i + 1][j + 1];
                    }
                } else {
                    j--;
                    assert(j >= 0);

                    // do consume s
                    // this can be optimised
                    for (int k = i; k >= 0 && (s[k] == p[j] || p[j] == '.'); k--) {
                        dp[k][j] |= dp[i + 1][j + 2];
                    }

                    // do not consume s
                    dp[i][j] |= dp[i][j + 2]; // hack for i = 0
                    dp[i + 1][j] |= dp[i + 1][j + 2];
                }
                j--;
            }
        }

        return dp[0][0];
    }
};