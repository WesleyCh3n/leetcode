pub struct Solution {}

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let mut result = vec![0; n as usize + 1];
        result[0] = 1;
        result[1] = 1;
        for i in 2..=n as usize {
            result[i] = result[i - 1] + result[i - 2];
        }
        result[n as usize]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution {};
        assert_eq!(Solution::climb_stairs(3), 3);
    }
}
