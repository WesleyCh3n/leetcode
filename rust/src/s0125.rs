pub struct Solution {}

impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let s_iter = s
            .chars()
            .into_iter()
            .filter(|c| c.is_alphanumeric())
            .map(|c| c.to_ascii_lowercase());
        s_iter.to_owned().eq(s_iter.rev())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution::is_palindrome("a.".to_string());
    }
}
