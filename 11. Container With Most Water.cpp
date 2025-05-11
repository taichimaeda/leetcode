#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        if (height.size() == 2) {
            return min(height[0], height[1]);
        }

        // variant of two-pointer method
        int l = 0, r = height.size() - 1;
        long ans = 0;
        while (r - l >= 1) {
            long h = min(height[l], height[r]);
            ans = max(ans, h * (r - l));
            
            if (height[l] < height[r]) {
                // for l+1 no need to check [r,n)
                // because for every k in [r,n), height[l] >= height[k]
                l++;
            } else {
                // similarly for r+1
                r--;
            }
        }

        return ans;
    }
};
