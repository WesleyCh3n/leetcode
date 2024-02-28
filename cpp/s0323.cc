class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for(const auto &edge: edges) {
      g[edge[0]].emplace_back(edge[1]);
      g[edge[1]].emplace_back(edge[0]);
    }

    vector<bool> visited(n, false);
    int result = 0;
    for (int node = 0; node < g.size(); node++) {
      if (!visited[node]) {
        result += 1;
        dfs(g, visited, node);
      }
    }
    return result;
  }
  void dfs(vector<vector<int>> &g, vector<bool> &visited, int node) {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    for (int i = 0; i < g[node].size(); i++) {
      dfs(g, visited, g[node][i]);
    }
  }
};

class Solution1 {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
    int result = n;
    for (const auto &edge: edges) {
      result -= _union(p, edge[0], edge[1]);
    }
    return result
  }
  int find(vector<int> &p, int node) {
    if (p[node] != node)
      return find(p, p[node]);
    return node;
  }
  int _union(vector<int> &p, int x, int y) {
    int px = find(p, x), py = find(p, y);
    if (px != py) {
      p[px] = py;
      return 1;
    }
    return 0;
  }
};
