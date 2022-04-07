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
  void solve(vector<vector<int>> &ans, vector<int> comb, vector<int> nums, int start) {
    if ((int)comb.size() == (int)nums.size()) {
      ans.push_back(comb);
      return;
    }
    for (int i = start; i < (int)nums.size() - 1; ++i) {
      swap(nums[i], nums[i+1]);
      solve(ans, comb, nums, i);
      swap(nums[i], nums[i+1]);
    }
  }
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> comb;
    solve(ans, comb, nums, 0);
    return ans;
  }
};

int main() {
  std::vector<int> v = {1, 2, 3};

  Solution s;
  auto ans = s.permute(v);
  for (auto v: ans) {
    print_vec(v);
  }
  return 0;
}
