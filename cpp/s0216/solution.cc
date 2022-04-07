#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> void print_vec(vector<T> &v) {
  cout << '[' << ' ';
  for (auto i : v)
    cout << i << ' ';
  cout << ']' << '\n';
}

class Solution {
private:
  void solve(vector<vector<int>> &ans, vector<int> comb, int target, int num,
             int start) {
    if ((int)comb.size() == num && target == 0) {
      ans.push_back(comb);
      return;
    }
    if (target < 0)
      return;
    for (int i = start; i <= 9; ++i) {
      comb.push_back(i);
      solve(ans, comb, target - i, num, i + 1);
      comb.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> comb;
    solve(ans, comb, n, k, 1);
    return ans;
  }
};

int main() {
  Solution s;
  auto ans = s.combinationSum3(3, 9);
  for (auto v : ans) {
    print_vec(v);
  }
  return 0;
}
