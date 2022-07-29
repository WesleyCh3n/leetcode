pub struct Solution {}

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {

    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution::remove_duplicates(&mut vec![0,0,1,1,1,2,2,3,3,4]);
    }
}
