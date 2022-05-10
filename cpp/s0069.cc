#include <algorithm>
#include <iostream>
#include <string>
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
  string addBinary(string a, string b) {
    string ans;
    int i(a.size() - 1), j(b.size() - 1);
    int carray(0);

    while(i >=0 || j >= 0) {
      int sum = carray;
      if (i >= 0) {
        sum += a[i--] - '0';
      }
      if (j >= 0) {
        sum += b[j--] - '0';
      }
      carray = (sum > 1)? 1 : 0;
      ans += to_string(sum % 2);
    }
    if (carray) {
      ans += to_string(carray);
    }
    reverse(ans.begin(), ans.end());

    return ans;
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
