#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        
        // not cheating
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};