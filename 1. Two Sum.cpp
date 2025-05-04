#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<int> vals{nums.begin(), nums.end()};

        for (int i = 0; i < nums.size(); i++) {
            if (vals.find(target - nums[i]) == vals.end()) {
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};
