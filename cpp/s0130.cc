class Solution {
public:
    void solve(vector<vector<char>>& board) {
      // from border to find 'O' and start traverse to flip it the 'T'
      // first/last col
      for (int m = 0; m < board.size(); m++) {
        dfs(board, m, 0);
        dfs(board, m, board[0].size()-1);
      }
      // first/last row
      for (int n = 0; n < board[0].size(); n++) {
        dfs(board, 0, n);
        dfs(board, board.size()-1, n);
      }
      for (int m = 0; m < board.size(); m++) {
        for (int n = 0; n < board[0].size(); n++) {
          if (board[m][n] == 'O')
            board[m][n] = 'X';
          if (board[m][n] == 'T')
            board[m][n] = 'O';
        }
      }
    }
    void dfs(vector<vector<char>>& board, int m, int n) {
      if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size()) {
        return;
      }
      if (board[m][n] != 'O')
        return;
      board[m][n] = 'T';
      // traverse 4 direction
      dfs(board, m-1, n);
      dfs(board, m+1, n);
      dfs(board, m, n-1);
      dfs(board, m, n+1);
    }
};
