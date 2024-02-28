class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[s.size()] = true;

    for (int i = s.size() - 1; i >= 0; i--) {
      for (string &word: wordDict) {
        if ((s.size() - i >= word.size()) && s.substr(i, word.size()) == word) {
          dp[i] = dp[i + word.size()];
          if (dp[i])
            break;
        }
      }
    }
    return dp[0];
  }
};
