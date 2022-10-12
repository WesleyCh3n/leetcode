use std::collections::hash_set::HashSet;
pub struct Solution {}

impl Solution {
    pub fn contains_duplicate(mut nums: Vec<i32>) -> bool {
        nums.sort();
        for i in 0..nums.len() - 1 {
            if nums[i] == nums[i + 1] {
                return true;
            }
        }
        false
    }
    pub fn contains_duplicate_hash(nums: Vec<i32>) -> bool {
        let mut s: HashSet<i32> = HashSet::new();
        for i in nums {
            if s.contains(&i) {
                return true;
            } else {
                s.insert(i);
            }
        }
        false
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn contains_duplicate_test() {
        assert_eq!(Solution::contains_duplicate(vec![1, 2, 3, 4]), false);
        assert_eq!(Solution::contains_duplicate(vec![1, 1, 3, 4]), true);
        assert_eq!(Solution::contains_duplicate_hash(vec![1, 2, 3, 4]), false);
        assert_eq!(Solution::contains_duplicate_hash(vec![1, 1, 3, 4]), true);
    }
}
