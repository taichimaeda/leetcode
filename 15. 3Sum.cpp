#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort nums to make sure
        // triplets [nums[i], nums[j], nums[k]] are unique
        sort(nums.begin(), nums.end());

        if (nums.size() < 3) return {};
        if (nums[0] > 0) return {};

        unordered_map<int, int> indices{};
        for (int i = 0; i < nums.size(); i++) {
            // only leaves last i with key = num[i]
            indices[nums[i]] = i;
        }

        vector<vector<int>> ans{};
        for (int i = 0; i < nums.size(); i++) {
            // if num[i] is the same as previous iteration
            // this iteration ends up pushing subset of the same sums
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                auto it = indices.find(-(nums[i] + nums[j]));
                if (it == indices.end()) {
                    continue;
                }

                int k = it->second;
                if (k <= j) {
                    continue;
                }
                
                // nums is already sorted
                ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ans;
    }
};
