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
  void solve(vector<vector<int>> &ans, vector<int> comb, vector<int> nums,
             int size, int index) {
    if (size == 0) {
      ans.push_back(comb);
      return;
    }
    for (int i = index; i < (int)nums.size(); ++i) {
      // don't push current item
      solve(ans, comb, nums, size - 1, i + 1);

      // push current item
      comb.push_back(nums[i]);
      solve(ans, comb, nums, size - 1, i + 1);
    }
  }

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> comb;
    solve(ans, comb, nums, nums.size(), 0);
    return ans;
  }
};

int main() {
  std::vector<int> v = {1,2,3};
  Solution s;
  auto ans = s.subsets(v);
  for(auto v: ans) {
    print_vec(v);
  }
  return 0;
}
