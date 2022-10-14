pub struct Solution {}

impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let mut result = vec![1; nums.len()];
        let mut prefix = 1;
        for (i, &num) in nums.iter().enumerate() {
            result[i] = prefix;
            prefix *= num;
        }
        let mut postfix = 1;
        for (i, &num) in nums.iter().enumerate().rev() {
            result[i] = postfix * result[i];
            postfix *= num;
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution::product_except_self(vec![1, 2, 3, 4]);
    }
}
