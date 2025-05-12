#include <bits/stdc++.h>
#include <ranges>

using namespace std;

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        assert(nums.size() >= 3);
        if (nums.size() == 3) {
            return reduce(nums.begin(), nums.end());
        }

        sort(nums.begin(), nums.end());

        // avoid overflow in update()
        long ans = INT_MAX;
        auto update = [&](int sum) {
            if (abs(target - ans) > abs(target - sum)) {
                ans = sum;
            }
        };

        for (int i = 0; i < nums.size(); i++)
        for (int j = i + 1; j < nums.size(); j++) {
            int sum = nums[i] + nums[j];
            int key = target - sum;

            // start with j + 1 to remove duplicates
            if (nums.begin() + j + 1 == nums.end()) {
                break;
            }
            auto it = lower_bound(nums.begin() + j + 1, nums.end(), key);

            if (it == nums.begin() + j + 1) {
                update(sum + *it);
                continue;
            }
            if (it == nums.end()) {
                update(sum + *(it - 1));
                continue;
            }
            
            update(sum + *it);
            update(sum + *(it - 1));
        }
        return static_cast<int>(ans);
    }
};