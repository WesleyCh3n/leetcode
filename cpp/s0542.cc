#include "essential.h"

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int row = mat.size(), col = mat[0].size();
    vector<vector<int>> dp(row, vector<int>(col, INT_MAX - 1));
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (mat[i][j] == 0) {
          dp[i][j] = 0;
        } else {
          if (j > 0) {
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
          }
          if (i > 0) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
          }
        }
      }
    }
    for (int i = row - 1; i >= 0; i--) {
      for (int j = col - 1; j >= 0; j--) {
        if (mat[i][j] != 0) {
          if (j < col - 1) {
            dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
          }
          if (i < row - 1) {
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
          }
        }
      }
    }
    return dp;
  }
  vector<vector<int>> updateMatrix_O1space(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size(),
        INF = m + n; // The distance of cells is up to (M+N)
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        if (mat[r][c] == 0)
          continue;
        int top = INF, left = INF;
        if (r - 1 >= 0)
          top = mat[r - 1][c];
        if (c - 1 >= 0)
          left = mat[r][c - 1];
        mat[r][c] = min(top, left) + 1;
      }
    }
    for (int r = m - 1; r >= 0; r--) {
      for (int c = n - 1; c >= 0; c--) {
        if (mat[r][c] == 0)
          continue;
        int bottom = INF, right = INF;
        if (r + 1 < m)
          bottom = mat[r + 1][c];
        if (c + 1 < n)
          right = mat[r][c + 1];
        mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
      }
    }
    return mat;
  }
};

int main() {
  std::vector<int> v = {};

  Solution s;

  return 0;
}
