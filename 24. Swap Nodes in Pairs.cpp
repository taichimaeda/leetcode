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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* curr = head;
        ListNode* prev{};
        ListNode* ret{};

        while (curr != nullptr && curr->next != nullptr) {
            ListNode* next = curr->next;
            ListNode* next2 = next->next;
            curr->next = next2;
            next->next = curr;
            if (prev != nullptr) {
                prev->next = next;
            }
            if (ret == nullptr) {
                ret = next;
            }
            prev = curr;
            curr = next2;
        }
        return ret;
    }
};