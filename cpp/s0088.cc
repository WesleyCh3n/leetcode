#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_vec(vector<T> &v) {
  cout << '[' << ' ';
  for (auto i : v)
    cout << i << ' ';
  cout << ']' << '\n';
}

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {
      // cout << "i: " << i << " j: " << j << " k: " << k << '\n';
      if (i >= 0 && nums1[i] > nums2[j]) {
        nums1[k] = nums1[i--];
      } else {
        nums1[k] = nums2[j--];
      }
      // print_vec<int>(nums1);
      k--;
    }
  }
};

int main() {
  std::vector<int> v = {2, 5, 6, 0, 0, 0};
  std::vector<int> v1 = {1, 2, 3};

  Solution s;
  s.merge(v, 3, v1, 3);

  print_vec<int>(v);
  return 0;
}
