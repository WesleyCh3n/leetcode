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
  int binarySearch(vector<int> &nums, int target, int start, int end) {
    int mid = (start + end) / 2;
    if (start > end) {
      return -1;
    }
    if (target == nums[mid]) {
      return mid;
    } else if (target < nums[mid]) {
      return binarySearch(nums, target, start, mid - 1);
    } else if (target > nums[mid]) {
      return binarySearch(nums, target, mid + 1, end);
    }
    return -1;
  }

  int search(vector<int> &nums, int target) {
    return binarySearch(nums, target, 0, (int)nums.size() - 1);
  }
};

int main() {
  Solution s;

  std::vector<int> v = {-1, 0, 3, 5, 9, 12};
  cout << s.search(v, 9) << '\n';

  v = {-1, 0, 3, 5, 9, 12};
  cout << s.search(v, 4) << '\n';
  ;

  return 0;
}
