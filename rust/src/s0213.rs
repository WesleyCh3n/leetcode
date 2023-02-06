impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        //
        let n = nums.len();
        if n == 1 {
            return nums[0];
        }
        std::cmp::max(
            Self::bottom_up(&nums[..n - 1]),
            Self::bottom_up(&nums[1..]),
        )
    }
    pub fn bottom_up(nums: &[i32]) -> i32 {
        let mut dp = vec![0; nums.len() + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for i in 1..nums.len() {
            dp[i + 1] = std::cmp::max(dp[i - 1] + nums[i], dp[i])
        }
        dp[nums.len()]
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        assert_eq!(Solution::rob(vec![2, 3, 2]), 3);
        assert_eq!(Solution::rob(vec![1, 2, 3, 1]), 4);
    }
}
