#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  string foreignDictionary(vector<string> &words) {
    unordered_map<char, unordered_set<char>> map;
    for (int i = 0; i < words.size() - 1; i++) {
      // find first different between words[i] & words[i+1]
      string &first = words[i];
      string &second = words[i + 1];
      int len = min(first.size(), second.size());
      for (int j = 0; j < len; j++) {
        if (first[j] != second[j]) {
          map[first[j]].insert(second[j]);
          break;
        }
        if (j == len - 1 && first.size() > second.size()) {
          return "";
        }
      }
    }

    unordered_map<char, bool> visited;
    string res;
    for (const auto &it : map) {
      if (dfs(it.first, map, visited, res)) {
        return "";
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }

  bool dfs(const char &c, unordered_map<char, unordered_set<char>> &map,
           unordered_map<char, bool> &visited, string &res) {
    if (visited.count(c) > 0) {
      return visited[c];
    }

    visited[c] = true;
    for (const char &desc : map[c]) {
      if (dfs(desc, map, visited, res)) {
        return true;
      }
    }
    visited[c] = false;

    res += c;
    return visited[c];
  }
};
