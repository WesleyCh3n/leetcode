#include "essential.h"
#include <queue>

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    vector<vector<int>> answer(k);
    priority_queue<vector<int>> maxHeap;

    for (auto &p : points) {
      int x(p[0]), y(p[1]);
      maxHeap.push({x * x + y * y, x, y});
      if (maxHeap.size() > k) {
        maxHeap.pop();
      }
    }

    for (int i = 0; i < k; i++) {
      vector<int> top = maxHeap.top();
      maxHeap.pop();
      answer[i] = {top[1], top[2]};
    }
    return answer;
  }
};

int main() { return 0; }
