#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      if (nums.size() < 4) return {};
      
      // sort nums to make sure
      // quadruples [nums[a], nums[b], nums[c], nums[d]] are unique
      sort(nums.begin(), nums.end());

      vector<long long> llnums(nums.size());
      for (int i = 0; i < nums.size(); i++) {
        llnums[i] = static_cast<long long>(nums[i]);
      }

      vector<vector<int>> ans{};
      for (int a = 0; a <= llnums.size() - 4; a++) {
        if (a > 0 && llnums[a] == llnums[a - 1]) {
          continue;
        }

        for (int b = a + 1; b <= llnums.size() - 3; b++) {
          if (b > a + 1 && llnums[b] == llnums[b - 1]) {
            continue;
          }

          for (int c = b + 1; c <= llnums.size() - 2; c++) {
            if (c > b + 1 && llnums[c] == llnums[c - 1]) {
              continue;
            }

            long long total = llnums[a] + llnums[b] + llnums[c];
            auto it = lower_bound(llnums.begin() + c + 1, llnums.end(), target - total);
            if (it != llnums.end() && *it == target - total) {
              int d = it - llnums.begin();
              ans.push_back({
                static_cast<int>(llnums[a]), 
                static_cast<int>(llnums[b]), 
                static_cast<int>(llnums[c]), 
                static_cast<int>(llnums[d]),
              });
            }
          }
        }
      }
      return ans;
    }
};