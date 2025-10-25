#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        // certainly not cheating
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};
