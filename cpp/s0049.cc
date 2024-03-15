class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for(string &str: strs) {
      array<int, 26> count{};
      for (char &c: str) {
        count[c - 'a'] += 1;
      }
      map[get_key(count)].emplace_back(str);
    }
    vector<vector<string>> result;
    for(auto &[key, values]: map) {
      result.emplace_back(values);
    }
    return result;
  }

  string get_key(array<int, 26> &count) {
    string key = "";
    for(int &c: count) {
      key += to_string(c) + ",";
    }
    return key;
  }
};
