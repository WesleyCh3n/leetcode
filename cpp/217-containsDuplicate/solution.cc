#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] == nums[i+1])
        return true;
    }
    return false;
  }
};

int main() {
  std::vector<int> v = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

  Solution s;
  cout << s.containsDuplicate(v) << '\n';

  return 0;
}
