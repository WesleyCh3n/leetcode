#include <algorithm>
#include <iostream>
#include <set>
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
  void getComb(vector<int> &nums, int index, int target, vector<int> &currComb,
               vector<vector<int>> &ans) {
    if (target == 0) {
      ans.push_back(currComb);
      return;
    }
    if (target < 0)
      return;
    for (int i = index; i < (int)nums.size(); i++) {
      // not doing the same thing at previous iteration
      if (i > index && nums[i] == nums[i - 1])
        continue;
      currComb.push_back(nums[i]);
      getComb(nums, i + 1, target - nums[i], currComb, ans);
      currComb.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> comb;
    sort(candidates.begin(), candidates.end());
    getComb(candidates, 0, target, comb, ans);
    return ans;
  }
};

int main() {
  std::vector<int> v = {10, 1, 2, 7, 6, 1, 5};

  Solution s;
  // for (auto vec : s.combinationSum2(v, 8)) {
  // print_vec<int>(vec);
  // }

  v = {2, 5, 2, 1, 2};

  auto ans = s.combinationSum2(v, 5);
  cout << "Ans:\n";
  for (auto vec : ans) {
    print_vec<int>(vec);
  }

  return 0;
}
