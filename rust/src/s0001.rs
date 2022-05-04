pub struct Solution {}

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut ans: Vec<i32> = Vec::with_capacity(2);
        use std::collections::HashMap;
        let mut map: HashMap<i32, i32> = HashMap::new();
        for i in 0..nums.len() {
            match map.get_key_value(&(target - nums[i])) {
                Some((_, index)) => {
                    ans.push(i as i32);
                    ans.push(*index);
                }
                None => {
                    map.entry(nums[i]).or_insert(i as i32);
                }
            }
        }

        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        let mut ans = Solution::two_sum(vec![2, 7, 11, 15], 9);
        ans.sort();
        assert_eq!(ans, [0, 1]);
        let mut ans = Solution::two_sum(vec![3, 3], 6);
        ans.sort();
        assert_eq!(ans, [0, 1]);
    }
}
