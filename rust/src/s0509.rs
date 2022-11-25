impl Solution {
    pub fn fib(n: i32) -> i32 {
        let mut memo = vec![0; n as usize + 1];
        Self::dp(&mut memo, n)
    }
    pub fn recusive(n: i32) -> i32 {
        if n == 0 || n == 1 {
            return n;
        }
        Self::recusive(n - 1) + Self::recusive(n - 2)
    }
    // top-down dp
    pub fn dp(memo: &mut [i32], n: i32) -> i32 {
        if n == 0 || n == 1 {
            return n;
        }
        if memo[n as usize] != 0 {
            return memo[n as usize];
        }
        memo[n as usize] = Self::dp(memo, n - 1) + Self::dp(memo, n - 2);

        memo[n as usize]
    }
    // bottom-up dp
    pub fn dp_btm_up(n: i32) -> i32 {
        // time complexity: O(n)
        // space complexity: O(n)
        if n == 0 {
            return 0;
        }
        let mut dp = vec![0; n as usize + 1];
        dp[0] = 0;
        dp[1] = 1;
        for i in 2..=n as usize {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        dp[n as usize]
    }
    // optimize
    pub fn dp_optimize(n: i32) -> i32 {
        // time complexity: O(n)
        // space complexity: O(1)
        if n == 0 || n == 1 {
            return n;
        }
        let (mut dp_1, mut dp_2) = (0, 1);
        let mut dp_curr = 0;
        for _ in 2..=n {
            dp_curr = dp_1 + dp_2;
            dp_1 = dp_2;
            dp_2 = dp_curr;
        }
        dp_curr
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution {};
        assert_eq!(Solution::recusive(2), 1);
        assert_eq!(Solution::recusive(3), 2);
        assert_eq!(Solution::recusive(4), 3);

        let mut memo = [0; 2 + 1];
        assert_eq!(Solution::dp(&mut memo, 2), 1);
        let mut memo = [0; 3 + 1];
        assert_eq!(Solution::dp(&mut memo, 3), 2);
        let mut memo = [0; 4 + 1];
        assert_eq!(Solution::dp(&mut memo, 4), 3);

        assert_eq!(Solution::dp_optimize(2), 1);
        assert_eq!(Solution::dp_optimize(3), 2);
        assert_eq!(Solution::dp_optimize(4), 3);
    }
}
