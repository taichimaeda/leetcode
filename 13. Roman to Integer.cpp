#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int romanToInt(string s) {
        // slow due to runtime lookup
        unordered_map<char, int> vals{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        
        int i = 0;
        int ans = 0;
        while (i < s.size()) {
            if (i + 1 < s.size() && 
                  ((s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                || (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                || (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')))) {
                ans += vals.at(s[i + 1]) - vals.at(s[i]);
                i += 2;
                continue;
            }
            ans += vals.at(s[i]);
            i++;
        }

        return ans;
    }
};