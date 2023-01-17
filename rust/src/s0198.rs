pub struct Solution {}

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        // Self::top_down(&nums, (nums.len() - 1) as i32)
        //
        Self::bottom_up(&nums)
    }
    pub fn top_down(nums: &Vec<i32>, i: i32) -> i32 {
        if i < 0 {
            return 0;
        }
        std::cmp::max(
            Self::top_down(nums, i - 2) + nums[i as usize],
            Self::top_down(nums, i - 1),
        )
    }
    pub fn bottom_up(nums: &Vec<i32>) -> i32 {
        let mut dp = vec![0; nums.len() + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for i in 1..nums.len() {
            dp[i + 1] = std::cmp::max(dp[i - 1] + nums[i], dp[i])
        }
        dp[nums.len()]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        assert_eq!(Solution::rob(vec![1, 2, 3, 1]), 4);
    }
}
