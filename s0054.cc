class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = n - 1, t = 0, b = m - 1;
    vector<int> res;
    while (l <= r && t <= b) {
      // iter tl tr
      for (int i = l; i <= r; i++) {
        res.emplace_back(matrix[t][i]);
      }
      t += 1;
      // iter tr br
      for (int i = t; i <= b; i++) {
        res.emplace_back(matrix[i][r]);
      }
      r -= 1;
      if (t > b || l > r) {
        break;
      }
      // iter br bl
      for (int i = r; i >= l; i--) {
        res.emplace_back(matrix[b][i]);
      }
      b -= 1;
      // iter bl tl
      for (int i = b; i >= t; i--) {
        res.emplace_back(matrix[i][l]);
      }
      l += 1;
    }
    return res;
  }
};
