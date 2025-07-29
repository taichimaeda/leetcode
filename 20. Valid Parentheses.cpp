#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) {
            return false;
        }

        stack<char> st{};
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            if (c == ')' || c == ']' || c == '}') {
                if (st.empty()) {
                    return false;
                }
                char top = st.top(); st.pop();
                if (c == ')' && top != '(') {
                    return false;
                }
                if (c == ']' && top != '[') {
                    return false;
                }
                if (c == '}' && top != '{') {
                    return false;
                }
            }
        }

        return st.empty();
    }
};