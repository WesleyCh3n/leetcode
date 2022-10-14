pub struct Solution {}

impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();
        nums.sort();
        for i in 0..nums.len() {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            let mut left = i + 1;
            let mut right = nums.len() - 1;
            while left < right {
                let sum = nums[i] + nums[left] + nums[right];

                use std::cmp::Ordering::{Equal, Greater, Less};
                match sum.cmp(&0) {
                    Less => left += 1,
                    Greater => right -= 1,
                    Equal => {
                        result.push(vec![nums[i], nums[left], nums[right]]);
                        left += 1;
                        while nums[left] == nums[left - 1] && left < right {
                            left += 1;
                        }
                    }
                }
            }
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        println!("{:?}", Solution::three_sum(vec![-1, 0, 1, 2, -1, -4]));
    }
}
