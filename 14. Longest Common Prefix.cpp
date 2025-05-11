#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        int len = INT_MAX;
        for (const auto str : strs) {
            len = min(len, static_cast<int>(str.size()));
        }

        auto cond = [&](int i) {
            auto it = strs[0].begin();
            string_view prefix{it, it + i};
            for (const auto str : strs) {
                if (!str.starts_with(prefix)) {
                    return false;
                }
            }
            return true;
        };

        // binary search for fun
        // s[0, ok) is prefix of all strs
        int ok = 0, ng = len + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (cond(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }            
        }

        return strs[0].substr(0, ok);
   }
};