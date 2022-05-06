#include <cctype>
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
  bool isPalindrome(string s) {
    int l = 0, r = (int)s.size() - 1;
    while (l < r) {
      if (!std::isalnum(s[l])) {
        // if l position is not char add one
        l++;
      } else if (!std::isalnum(s[r])) {
        // if r position is not char sub one
        r--;
      } else if (std::tolower(s[l]) != std::tolower(s[r])) {
        // if char not same
        return false;
      } else {
        // if same continue
        l++;
        r--;
      }
    }
    return true;
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  cout << s.isPalindrome("A man, a plan, a canal: Panama") << '\n';

  return 0;
}
