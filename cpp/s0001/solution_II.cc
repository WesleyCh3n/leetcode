#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::vector<int> v = {0,0};
    std::unordered_map<int, int> t;
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (t.count(target - nums[i])) {
        v[0] = i;
        v[1] = t[target - nums[i]];
        return v;
      } else {
        t[nums[i]] = i;
      }
    }
    return v;
  }
};

int main() {
  std::vector<int> v = {2, 7, 11, 15};

  Solution s;

  cout << '[' << ' ';
  for (auto i : s.twoSum(v, 9))
    cout << i << ' ';
  cout << ']' << '\n';

  return 0;
}
