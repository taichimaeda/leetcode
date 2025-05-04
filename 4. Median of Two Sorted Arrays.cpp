#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if (nums1.empty()) {
            int pos = (nums2.size() + 2) / 2 - 1;
            if (nums2.size() % 2 == 0) {
                return static_cast<double>(nums2[pos - 1] + nums2[pos]) / 2;
            } else {
                return nums2[pos];
            }
        }
        if (nums2.empty()) {
            int pos = (nums1.size() + 2) / 2 - 1;
            if (nums1.size() % 2 == 0) {
                return static_cast<double>(nums1[pos - 1] + nums1[pos]) / 2;
            } else {
                return nums1[pos];
            }
        }

        // ok finds rightmost index in nums2 that belongs to
        // the bottom half of merged and sorted array of nums1 and nums2
        int ok = -1, ng = nums2.size();
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            auto it = lower_bound(nums1.begin(), nums1.end(), nums2[mid]);
            int pos = it - nums1.begin() - 1;
            if (pos + mid + 2 <= (len + 2) / 2) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        if (ok == -1) {
            int pos = (len + 2) / 2 - 1;
            if (len % 2 == 0) {
                return static_cast<double>(nums1[pos - 1] + nums1[pos]) / 2;
            } else {
                return nums1[pos];
            }
        }

        auto it = lower_bound(nums1.begin(), nums1.end(), nums2[ok]);
        int pos = it - nums1.begin() - 1;
        int rem = (len + 2) / 2 - (pos + ok + 2);

        // After merging and sorting nums1 and nums2
        // only top 2 elements from each can be involved in the calculation of the median
        priority_queue<int> heap{};
        if (0 <= pos + rem && pos + rem < nums1.size())
            heap.push(nums1[pos + rem]);
        if (0 <= pos + rem - 1 && pos + rem - 1 < nums1.size())
            heap.push(nums1[pos + rem - 1]);
        if (0 <= ok && ok < nums2.size())
            heap.push(nums2[ok]);
        if (0 <= ok - 1 && ok - 1 < nums2.size())
            heap.push(nums2[ok - 1]);

        if (len % 2 == 0) {
            int num1 = heap.top();
            heap.pop();
            int num2 = heap.top();
            heap.pop();
            return static_cast<double>(num1 + num2) / 2;
        } else {
            int num1 = heap.top();
            heap.pop();
            return num1;
        }
    }
};