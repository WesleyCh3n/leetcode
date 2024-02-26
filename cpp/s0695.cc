class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int max_area = 0;
      for (int m = 0; m < grid.size(); m++) {
        for (int n = 0; n < grid[0].size(); n++) {
          if (grid[m][n] == 1) {
            int area = 0;
            dfs(grid, m, n, area);
            max_area = max(max_area, area);
          }
        }
      }
      return max_area;
    }

    void dfs(vector<vector<int>>& grid, int m, int n, int &area){
      if (m < 0 || m >= grid.size() || n < 0 || n >= grid[0].size()) return; // edge case
      if (grid[m][n] == 0) return; // nothing here
      area += 1;
      grid[m][n] = 0; // mark as traverse
      // traverse 4 direction
      dfs(grid, m, n-1, area);
      dfs(grid, m, n+1, area);
      dfs(grid, m-1, n, area);
      dfs(grid, m+1, n, area);
    }
};
