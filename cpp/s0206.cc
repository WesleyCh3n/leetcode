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

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr, *next;
    while(head) {
      next = head->next;
      head->next = prev;

      prev = head;
      head = next;
    }
    return prev;
  }
  ListNode *reverseList_recursive(ListNode *head, ListNode *prev) {
    if (head == nullptr) {
      return prev;
    }
    ListNode* next = head->next;
    head->next = prev;
    return reverseList_recursive(next, head);
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
