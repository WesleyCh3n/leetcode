/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (list.empty())
      return nullptr;
    if (lists.size() == 1)
      return lists[0];

    while (lists.size() > 1) {
      int list_len = lists.size() % 2 == 0 ? lists.size() : lists.size() + 1;
      vector<ListNode*> tmp_lists;
      for (int i = 0; i < list_len; i += 2) {
        ListNode *l1 = lists[i];
        ListNode *l2 = (i + 1) == lists.size() ? nullptr : lists[i + 1];
        tmp_lists.emplace_back(mergeLists(l1, l2));
      }
      lists = tmp_lists;
    }
    return lists[0];
  }

  ListNode* mergeLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }

    if (l1->val < l2->val) {
      l1->next = mergeLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeLists(l1, l2->next);
      return l2;
    }
  }
};
