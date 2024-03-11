#include <iostream>
#include <vector>

using namespace std;

template <typename T> void print_vec(vector<T> &v) {
  cout << '[' << ' ';
  for (auto i : v)
  cout << i << ' ';
  cout << ']' << '\n';
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
  : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  // TODO: can this be O(1) space?
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &ni) {
    vector<vector<int>> ans;
    for (auto i : intervals) {
      // totally outside insert
      if (i[1] < ni[0]) {
        ans.push_back(i);
      } else if (i[0] > ni[1]) {
        ans.push_back(ni);
        ni = i;
      }
      // overlap update new interval
      else if (i[1] >= ni[0] || i[0] <= ni[1]) {
        ni[0] = min(ni[0], i[0]);
        ni[1] = max(ni[1], i[1]);
      }
    }
    ans.push_back(ni);
    return ans;
  }
};

int main() {
  vector<std::vector<int>> v = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};

  Solution s;

  vector<int> ni = {4, 8};
  auto ans = s.insert(v, ni);
  for (auto a: ans) {
    print_vec(a);
  }

  return 0;
}







class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int& ns = newInterval[0], &ne = newInterval[1];
    vector<vector<int>> result;
    for (int i = 0; i < intervals.size(); i++) {
      if (ne < intervals[i][0]) {
        result.emplace_back(newInterval);
        result.insert(result.end(), intervals.begin() + i, intervals.end());
        return result;
      } else if (ns > intervals[i][1]) {
        result.emplace_back(intervals[i]);
      } else {
        ns = min(ns, intervals[i][0]);
        ne = max(ne, intervals[i][1]);
      }
    }
    result.emplace_back(newInterval);
    return result;
  }
};
