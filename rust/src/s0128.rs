pub struct Solution {}

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        use std::collections::HashSet;
        // let set: HashSet<i32> = HashSet::from_iter(nums.into_iter());

        let set: HashSet<i32> =
            nums.into_iter().fold(HashSet::new(), |mut set, num| {
                set.insert(num);
                set
            });

        let mut result = 0;
        for &v in set.iter() {
            if !set.contains(&(v - 1)) {
                let mut length = 1;
                while set.contains(&(v + length)) {
                    length += 1;
                }
                result = std::cmp::max(result, length)
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
        println!(
            "{:?}",
            Solution::longest_consecutive(vec![0, 3, 7, 2, 5, 8, 4, 6, 0, 1])
        );
    }
}
