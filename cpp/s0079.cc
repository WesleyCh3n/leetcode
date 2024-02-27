class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    for (int m = 0; m < board.size(); m++) {
      for (int n = 0; n < board[0].size(); n++) {
        if (dfs(board, m, n, 0, word))
          return true;
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>>& board, int m, int n, int i, string& word) {
    if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size() || board[m][n] == '#') {
      return false;
    }
    char c = board[m][n];
    if (word[i] != c)
      return false;

    if (i == word.size() - 1) {
      return word[i] == c;
    }

    board[m][n] = '#';
    if(dfs(board, m - 1, n, i + 1, word))
      return true;
    if(dfs(board, m + 1, n, i + 1, word))
      return true;
    if(dfs(board, m, n - 1, i + 1, word))
      return true;
    if(dfs(board, m, n + 1, i + 1, word))
      return true;
    board[m][n] = c;
    return false;
  }
};
