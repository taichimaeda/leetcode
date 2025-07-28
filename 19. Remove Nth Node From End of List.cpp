#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = [&] {
            int sz = 1;
            ListNode* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
                sz++;
            }
            return sz;
        }();

        // m is zero indexed
        int m = sz - n;
        if (m == 0) {
            return head->next;
        }

        int i = 0;
        ListNode* curr = head;
        while (curr->next != nullptr) {
            if (i == m - 1) {
                if (curr->next->next == nullptr) {
                    curr->next = nullptr;
                    return head;
                } else {
                    curr->next = curr->next->next;
                    return head;
                }
            }

            curr = curr->next;
            i++;
        }

        __builtin_unreachable();
    }
};