#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) {
            return s.size();
        }

        int l = 0, r = 0;
        set<char> seen{};
        int ans = 0;
        while (r < s.size()) {
            if (!seen.contains(s[r])) {
                seen.insert(s[r]);
                r++;
                ans = max(ans, r - l);
                continue;
            }
            seen.erase(s[l]);
            l++;
        }

        ans = max(ans, r - l);
        return ans;
    }
};