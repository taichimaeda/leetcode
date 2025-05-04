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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode{};
        ListNode* ret = curr;

        ListNode *p1 = l1, *p2 = l2;
        int carry = 0;

        while (true) {
            int n1 = p1 != nullptr ? p1->val : 0;
            int n2 = p2 != nullptr ? p2->val : 0;
            int sum = n1 + n2 + carry;
            curr->val = sum % 10;
            carry = sum / 10;

            if (p1 != nullptr) p1 = p1->next;
            if (p2 != nullptr) p2 = p2->next;
            if (p1 == nullptr && p2 == nullptr) break;

            curr->next = new ListNode{};
            curr = curr->next;
        }

        if (carry > 0) {
            curr->next = new ListNode{carry};
        }

        return ret;
    }
};