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


class Solution {
public:
  bool isPalindrome(string s) {
    int start = 0;
    int end = s.size() - 1;
    while(start < end) {
      while (!isalnum(s[start]) && start < end) {
        start += 1;
      }
      while (!isalnum(s[end]) && start < end) {
        end -= 1;
      }
      if (tolower(s[start]) != tolower(s[end])) {
        return false;
      }
      start += 1;
      end -= 1;
    }
    return true;
  }
  // bool is_char(char& c) {
  //   return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
  // }
};
