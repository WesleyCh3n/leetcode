class Solution {
public:
  bool validTree(int n, vector<vector<int>>& edges) {
    vector<unordered_set<int>> g(n);
    for (const auto &edge: edges){
      g[edge[0]].insert(edge[1]);
      g[edge[1]].insert(edge[0]);
    }

    queue<int> q;
    vector<int> visited(n, false);
    q.push(0);
    visited[0] = true;

    while(!q.empty()) {
      int node = q.front();
      q.pop();
      for(const int& child: g[node]) {
        if (visited[child])
          return false;
        visited[child] = true;
        q.push(child);
        g[child].erase(node); // remove another direction because it's undirected graph
      }
    }
    for (const bool& v: visited) {
      if (!v)
        return false;
    }
    return true;
  }
};

// dfs solution
class Solution {
public:
  bool validTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (const auto &edge: edges){
      g[edge[0]].emplace_back(edge[1]);
      g[edge[1]].emplace_back(edge[0]);
    }
    vector<bool> visited(n, false);
    if (!dfs_valid_tree(g, visited, 0, -1))
      return false;
    for (const bool& v: visited) {
      if (!v)
        return false;
    }
    return true;
  }

  // to resolve undirected graph, previous node need to be pass down
  bool dfs_valid_tree(vector<vector<int>> &g, vector<bool> &visited, int node, int prev) {
    if (visited[node])
      return false;
    visited[node] = true;
    for (int &v: g[node]) {
      if (v != prev)
        if (!dfs_valid_tree(g, visited, v, node))
          return false;
    }
    return true;
  }
};
