class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int len = matrix.size();
    if (len <= 1) { // nothing to do
      return;
    }
    int l = 0, r = len - 1;
    while (l < r) {
      for (int i = 0; i < r - l; i++) {
        int &tl = matrix[l][l + i]; // top left
        int &tr = matrix[l + i][r]; // top right
        int &br = matrix[r][r - i]; // bottom right
        int &bl = matrix[r - i][l]; // bottom left
        int tmptl = tl;
        tl = bl;
        bl = br;
        br = tr;
        tr = tmptl;
      }
      l += 1;
      r -= 1;
    }
  }
};
