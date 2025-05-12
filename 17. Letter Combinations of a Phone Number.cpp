#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }

        unordered_map<int, vector<char>> letters{
            {2, { 'a', 'b', 'c' }},
            {3, { 'd', 'e', 'f' }},
            {4, { 'g', 'h', 'i' }},
            {5, { 'j', 'k', 'l' }},
            {6, { 'm', 'n', 'o' }},
            {7, { 'p', 'q', 'r', 's' }},
            {8, { 't', 'u', 'v' }},
            {9, { 'w', 'x', 'y', 'z' }},
        };
        
        vector<string> ans{};
        // cannot use auto for recursive lambdas below C++23
        function<void(int, string)> dfs = [&](int i, string acc) {
            if (i == digits.size()) {
                ans.push_back(acc);
                return;
            }

            int d = digits[i] - '0';
            for (char c : letters[d]) {
                dfs(i + 1, acc + c);
            }
        };
        dfs(0, "");
        return ans;
    }
};