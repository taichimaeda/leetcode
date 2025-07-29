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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 1) {
            return lists[0];
        }

        int nonnulls = 0;
        for (auto list : lists) {
            if (list != nullptr) {
                nonnulls++;
            }
        }
        if (nonnulls == 0) {
            return nullptr;
        }
        if (nonnulls == 1) {
            for (auto list : lists) {
                if (list != nullptr) {
                    return list;
                }
            }
        }

        ListNode* ret = new ListNode{};
        ListNode* orig = ret;
        ListNode* last = ret;

        while (true) {
            vector<int> indices{};
            for (int i = 0; i < k; i++) {
                if (lists[i] != nullptr) {
                    indices.push_back(i);
                }
            }
            if (indices.size() == 0) {
                break;
            }

            vector<pair<int, ListNode**>> heads{};
            for (auto index : indices) {
                heads.emplace_back(lists[index]->val, &lists[index]);
            }

            auto [val, head] = *min_element(heads.begin(), heads.end());

            last = ret;
            ret->val = val;
            ret->next = new ListNode{};
            ret = ret->next;

            *head = (*head)->next;
        }

        delete last->next;
        last->next = nullptr;
        return orig;
    }
};