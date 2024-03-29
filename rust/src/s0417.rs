pub struct Solution {}

/*
determine wheater block will go to both pacific & atlantic
check pacific also check atlantic
*/

impl Solution {
    pub fn pacific_atlantic(height: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (m, n) = (height.len(), height[0].len());
        let mut result = Vec::new();
        let mut pacific: Vec<Vec<bool>> = vec![vec![false; n]; m];
        let mut atlantic: Vec<Vec<bool>> = vec![vec![false; n]; m];

        // for pacific as starting point
        // left
        for i in 0..m {
            Self::dfs(&height, &mut pacific, i, 0);
        }
        // up
        for i in 0..n {
            Self::dfs(&height, &mut pacific, 0, i);
        }
        // for atlantic as starting point
        // right
        for i in 0..m {
            Self::dfs(&height, &mut atlantic, i, n - 1);
        }
        // bottom
        for i in 0..n {
            Self::dfs(&height, &mut atlantic, m - 1, i);
        }

        for i in 0..m {
            for j in 0..n {
                if pacific[i][j] && atlantic[i][j] {
                    result.push(vec![i as i32, j as i32]);
                }
            }
        }
        result
    }

    fn dfs(
        height: &Vec<Vec<i32>>,
        visited: &mut Vec<Vec<bool>>,
        i: usize,
        j: usize,
    ) {
        let (m, n) = (height.len(), height[0].len());
        visited[i][j] = true;
        // right: i, j+1
        if j + 1 < n
            && visited[i][j + 1] != true
            && height[i][j] <= height[i][j + 1]
        {
            Self::dfs(height, visited, i, j + 1);
        }
        // left: i, j-1
        if j > 0
            && visited[i][j - 1] != true
            && height[i][j] <= height[i][j - 1]
        {
            Self::dfs(height, visited, i, j - 1);
        }
        // up: i-1, j
        if i > 0
            && visited[i - 1][j] != true
            && height[i][j] <= height[i - 1][j]
        {
            Self::dfs(height, visited, i - 1, j);
        }
        // down: i+1, j
        if i + 1 < m
            && visited[i + 1][j] != true
            && height[i][j] <= height[i + 1][j]
        {
            Self::dfs(height, visited, i + 1, j);
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
