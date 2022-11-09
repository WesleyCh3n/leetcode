pub struct Solution {}

impl Solution {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let mut result = 0;
        let (m, n) = (grid.len(), grid[0].len());
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == '1' {
                    result += 1;
                    Self::dfs(&mut grid, i, j);
                }
            }
        }
        result
    }

    fn dfs(grid: &mut Vec<Vec<char>>, i: usize, j: usize) {
        let (m, n) = (grid.len(), grid[0].len());
        if i >= m || j >= n {
            return;
        }
        if grid[i][j] == '0' {
            return;
        }
        grid[i][j] = '0';
        Self::dfs(grid, i + 1, j);
        Self::dfs(grid, i, j + 1);
        if i > 0 {
            Self::dfs(grid, i - 1, j);
        }
        if j > 0 {
            Self::dfs(grid, i, j - 1);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution {};
    }
}
