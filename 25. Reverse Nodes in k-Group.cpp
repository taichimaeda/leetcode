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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        ListNode *first1 = nullptr;
        ListNode *first2 = nullptr;
        ListNode *ret = nullptr;

        int index = 0;
        int total = 0;
        for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
            total++;
        }

        auto debug = [&] () {
            ListNode *h = ret != nullptr ? ret : head;
            for (ListNode *p = h; p != nullptr; p = p->next) {
                cout << p->val << ",";
            }
            cout << endl;
        };

        // debug();

        while (curr != nullptr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

            // debug();
        
            index++;
            if (index % k == 0) {
                if (index == k) {
                    first1 = head;
                    first2 = curr;
                    ret = prev;
                    prev = nullptr;
                } else {
                    first1->next = prev;
                    first1 = first2;
                    first2 = curr;
                    prev = nullptr;
                }

                if (total - index < k) {
                    first1->next = curr;
                    break;
                }
            }
        }
        return ret;
    }
};
