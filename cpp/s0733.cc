#include <iostream>
#include <vector>

using namespace std;

template <typename T> void print_vec(vector<T> &v) {
  cout << '[' << ' ';
  for (auto i : v)
    cout << i << ' ';
  cout << ']' << '\n';
}

class Solution {
public:
  // TODO: don't know why overflow on leetcode
  void solve(vector<vector<int>> &image, int sr, int sc, int oc, int &nc) {
    int width = image.size();
    int height = image[0].size();
    if (sr > 0 && image[sr - 1][sc] == oc) { // up
      image[sr - 1][sc] = nc;
      solve(image, sr - 1, sc, oc, nc);
    }
    if (sr + 1 < height && image[sr + 1][sc] == oc) { // down
      image[sr + 1][sc] = nc;
      solve(image, sr + 1, sc, oc, nc);
    }
    if (sc > 0 && image[sr][sc - 1] == oc) { // left
      image[sr][sc - 1] = nc;
      solve(image, sr, sc - 1, oc, nc);
    }
    if (sc + 1 < width && image[sr][sc + 1] == oc) { // right
      image[sr][sc + 1] = nc;
      solve(image, sr, sc + 1, oc, nc);
    }
    return;
  }
  void solve_dfs(vector<vector<int>> &image, int sr, int sc, int oc, int &nc) {
    if (sr < 0 || sr >= (int)image.size() || sc < 0 || sc >= (int)image[0].size() ||
        image[sr][sc] != oc || image[sr][sc] == nc) {
      return;
    }
    image[sr][sc] = nc;
    solve_dfs(image, sr - 1, sc, oc, nc);
    solve_dfs(image, sr + 1, sc, oc, nc);
    solve_dfs(image, sr, sc - 1, oc, nc);
    solve_dfs(image, sr, sc + 1, oc, nc);
  }
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    solve_dfs(image, sr, sc, image[sr][sc], newColor);
    // image[sr][sc] = newColor;
    return image;
  }
};

int main() {
  std::vector<std::vector<int>> v = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  Solution s;
  s.floodFill(v, 0, 0, 2);
  for (auto vec : v) {
    print_vec(vec);
  }
  v = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  s.floodFill(v, 1, 1, 2);
  for (auto vec : v) {
    print_vec(vec);
  }

  return 0;
}
