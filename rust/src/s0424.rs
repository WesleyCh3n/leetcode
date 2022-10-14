pub struct Solution {}

impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let s: Vec<char> = s.chars().collect();
        let mut length = 0;
        length
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        assert_eq!(Solution::character_replacement("ABAB".to_string(), 2), 4);
    }
}
