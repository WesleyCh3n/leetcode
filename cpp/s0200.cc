class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int result = 0;
    for (int m = 0; m < grid.size(); m++) {
      for (int n = 0; n < grid[0].size(); n++) {
        if (grid[m][n] == '1') {
          result += 1;
          dfs(grid, m, n);
        }
      }
    }
    return result;
  }
  void dfs(vector<vector<char>> &grid, int m, int n) {
    if (m < 0 || m >= grid.size() || n < 0 || n >= grid[0].size()) return; // edge case
    if (grid[m][n] == '0') return; // nothing further
    // mark as visited
    grid[m][n] = '0';
    // traverse 4 way up, down, left right
    dfs(grid, m, n-1);
    dfs(grid, m, n+1);
    dfs(grid, m-1, n);
    dfs(grid, m+1, n);
  }
};
