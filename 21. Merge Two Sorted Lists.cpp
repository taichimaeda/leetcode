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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode* ret = new ListNode{};
        ListNode* last = ret;
        ListNode* orig = ret;

        auto advance1 = [&] {
            last = ret;
            ret->val = curr1->val;
            ret->next = new ListNode{};
            ret = ret->next;
            curr1 = curr1->next;
        };

        auto advance2 = [&] {
            last = ret;
            ret->val = curr2->val;
            ret->next = new ListNode{};
            ret = ret->next;
            curr2 = curr2->next;
        };

        while (curr1 != nullptr || curr2 != nullptr) {
            if (curr1 != nullptr && curr2 != nullptr) {
                if (curr1->val <= curr2->val) {
                    advance1();
                } else {
                    advance2();
                }
            } else if (curr1 != nullptr) {
                advance1();
            } else if (curr2 != nullptr) {
                advance2();
            }
        }

        last->next = nullptr;
        return orig;
    }
};