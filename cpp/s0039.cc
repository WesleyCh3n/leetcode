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
  void getComb(vector<int> &nums, int index, int target, vector<int> &currComb,
               vector<vector<int>> &ans) {
    if (target == 0) {
      ans.push_back(currComb);
      cout << "Ans: ";
      print_vec(currComb);
      return;
    }
    if (target < 0) return;
    for (int i = index; i < (int)nums.size(); i++) {
      currComb.push_back(nums[i]);
      cout << index << ": ";
      print_vec(currComb);
      getComb(nums, i, target-nums[i], currComb, ans);
      currComb.pop_back();
    }
  }
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> comb;
    getComb(candidates, 0, target, comb, ans);
    return ans;
  }
};

int main() {
  std::vector<int> v = {2,3,5};

  Solution s;
  for (auto vec: s.combinationSum(v, 8)) {
    // print_vec<int>(vec);
  }

  return 0;
}
