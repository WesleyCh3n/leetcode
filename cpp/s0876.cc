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
  ListNode *middleNode(ListNode *head) {
    ListNode *mid_node;
    int len(0);
    while (head) {
      len++;
      if (len == 1) {
        mid_node = head;
      } else if (len % 2 == 0) {
        mid_node = mid_node->next;
      }
      if (head->next == nullptr) {
        break;
      }
      head = head->next;
    }
    return mid_node;
  }
  ListNode *middleNode_2pointer(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
