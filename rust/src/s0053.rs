pub struct Solution {}

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut sum = nums[0];
        let mut max_val = nums[0];
        for i in 1..nums.len() {
            sum = nums[i].max(sum + nums[i]);
            max_val = max_val.max(sum);
        }
        max_val
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn max_sub_array_test() {
        assert_eq!(Solution::max_sub_array(vec![-1]), -1);
        assert_eq!(Solution::max_sub_array(vec![-1, 0]), 0);
        assert_eq!(Solution::max_sub_array(vec![-8, -2]), -2);
        assert_eq!(
            Solution::max_sub_array(vec![-2, 1, -3, 4, -1, 2, 1, -5, 4]),
            6
        );
        assert_eq!(Solution::max_sub_array(vec![1, 2, 3, 4]), 10);
    }
}
