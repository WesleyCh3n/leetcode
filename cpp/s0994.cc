class Solution {
  private:
    std::vector<pair<int, int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
  public:
    int orangesRotting(vector<vector<int>>& grid) {
      // we need to know how much level a rotton path can be -> BFS

      uint32_t fresh = 0;
      queue<pair<int, int>> q;
      // push all rotten location to queue
      for (int m = 0; m < grid.size(); m++) {
        for (int n = 0; n < grid[0].size(); n++) {
          if (grid[m][n] == 2)
            q.push({m, n});
          if (grid[m][n] == 1)
            fresh += 1;
        }
      }


      // push first seperator
      q.push({-1, -1});

      int min = -1;
      while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        // seperator met, one level done
        if (x == -1 && y == -1) {
          min += 1;
          if (!q.empty())
            q.push({-1, -1});
        }
        // iter child
        for (const auto &dir: dirs) {
          int xc = x + dir.first;
          int yc = y + dir.second;
          // check boundary
          if (xc < 0 || xc >= grid.size() || yc < 0 || yc >= grid[0].size()) {
            continue;
          }
          // child fresh then rotten
          if (grid[xc][yc] == 1) { // valid child
            grid[xc][yc] = 2;
            q.push({xc, yc});
            fresh -= 1;
          }
        }
      }

      if (fresh != 0) {
        return -1;
      }

      return min;
    }
};
