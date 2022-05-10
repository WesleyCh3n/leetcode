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
public:
  int majorityElement(vector<int> &nums) {
    int cnt = 0, majority_num = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == majority_num) {
        cnt++;
      } else if (cnt > 0) {
        cnt--;
      } else {
        majority_num = nums[i];
      }
    }
    return majority_num;
  }
  int majorityElement_II(vector<int> &nums) {
    int majority_num(-1), cnt(0);
    for (auto n : nums) {
      if (cnt == 0) {
        majority_num = n;
      }
      cnt += (majority_num == n) ? 1 : -1;
    }
    return majority_num;
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
