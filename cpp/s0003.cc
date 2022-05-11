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
