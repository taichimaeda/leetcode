#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        vector<vector<char>> tab(numRows, vector<char>(s.size(), '\0'));

        int i = 0, j = 0;
        bool down = true;
        for (int k = 0; k < s.size(); k++) {
            tab[i][j] = s[k];

            if (down) {
                i++;
            } else {
                i--; j++;
            }

            if (down && i == numRows - 1) {
                down = false;
            }
            if (!down && i == 0) {
                down = true;
            }
        }

        stringstream ss{};
        for (int i = 0; i < numRows; i++) 
        for (int j = 0; j < s.size(); j++) {
            if (tab[i][j] != '\0') {
                ss << tab[i][j];
            }
        }
        return ss.str();
    }
};
