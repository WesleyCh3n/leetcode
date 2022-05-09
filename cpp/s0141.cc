#include <iostream>
#include <unordered_set>
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
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode *> set;
    while (head) {
      if (set.count(head) == 1) {
        return true;
      }
      set.insert(head);
      head = head->next;
    }
    return false;
  }
  /* Floyd’s Cycle-Finding Algorithm */
  bool hasCycle_2pointer(ListNode *head) {
    if (head == nullptr) {
      return false;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
