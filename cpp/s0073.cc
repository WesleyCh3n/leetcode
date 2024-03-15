class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    bool is_first_col_zero = false;
    bool is_first_row_zero = false;

    for (int i = 0; i < rows; i++) {
      if (matrix[i][0] == 0) {
        is_first_col_zero = true;
        break;
      }
    }
    for (int j = 0; j < cols; j++) {
      if (matrix[0][j] == 0) {
        is_first_row_zero = true;
      }
    }

    for (int i = 1; i < rows; i++) {
      for (int j = 1; j < cols; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0; // set left col zero
          matrix[0][j] = 0; // set top row zero
        }
      }
    }

    for (int i = 1; i < rows; i++) {
      for (int j = 1; j < cols; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0; // current need to be zero
        }
      }
    }

    if (is_first_col_zero) {
      for (int i = 0; i < rows; i++) {
         matrix[i][0] = 0;
      }
    }

    if (is_first_row_zero) {
      for (int i = 0; i < cols; i++) {
        matrix[0][i] = 0;
      }
    }

  }
};
