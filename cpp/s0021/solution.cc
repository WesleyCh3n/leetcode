#include <iostream>
#include <vector>

using namespace std;

template <typename T> void print_vec(vector<T> &v) {
  cout << '[' << ' ';
  for (auto i : v)
    cout << i << ' ';
  cout << ']' << '\n';
}

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* iterat Solution */
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr) {
      return list2;
    }
    if (list2 == nullptr) {
      return list1;
    }

    ListNode *head = list1;
    if (list1->val > list2->val) {
      head = list2;
      list2 = list2->next;
    } else {
      list1 = list1->next;
    }
    ListNode *curr = head;

    while (list1 && list2) {
      if (list1->val < list2->val) {
        curr->next = list1;
        list1 = list1->next;
      } else {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;
    }

    if (!list1) {
      curr->next = list2;
    } else {
      curr->next = list1;
    }

    return head;
  }

  ListNode *mergeTwoListsRecursive(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr) {
      return list2;
    }
    if (list2 == nullptr) {
      return list1;
    }

    if (list1->val < list2->val) {
      list1->next = mergeTwoListsRecursive(list1->next, list2);
      return list1;
    } else {
      list2->next = mergeTwoListsRecursive(list1, list2->next);
      return list2;
    }
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
