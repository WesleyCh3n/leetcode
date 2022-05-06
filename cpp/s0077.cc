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
  void solve(vector<vector<int>> &ans, vector<int> com, int index, int num,
             int cnt) {
    if ((int)com.size() == cnt) {
      ans.push_back(com);
      return;
    }
    for (int i = index; i <= num; ++i) {
      com.push_back(i);
      solve(ans, com, i + 1, num, cnt);
      com.pop_back();
    }
  }

public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> com;
    solve(ans, com, 1, n, k);
    return ans;
  }
};

int main() {
  Solution s;
  auto ans = s.combine(4, 2);
  for (auto &v : ans) {
    print_vec(v);
  }
  return 0;
}
