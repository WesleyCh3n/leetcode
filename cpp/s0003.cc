#include "essential.h"
#include <unordered_set>

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int len = s.size();
    unordered_set<char> st;
    int start(0), end(0), maxSize(0);
    while (end < len) {
      if (st.count(s[end]) == 0) {
        st.insert(s[end]);
        maxSize = max(maxSize, (int)st.size());
        end++;
      } else {
        st.erase(s[end + 1]);
        start++;
      }
    }
    return maxSize;
  }
};

int main() { return 0; }

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int left = 0, max_len = 0;
    for (int r = 0; r < s.size(); r++) {
      while (set.count(s[r])) {
        set.erase(s[left]);
        left += 1;
      }
      set.insert(s[r]);
      max_len = max(max_len, r - left + 1);
    }
    return max_len;
  }
};
