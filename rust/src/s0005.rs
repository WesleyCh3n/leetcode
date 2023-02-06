pub struct Solution {}

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let len = s.len();
        let mut max_len = 0;
        let mut max_end = 0;
        let mut arr: Vec<Vec<usize>> = vec![vec![0; len]; len];
        for (i, c1) in s.chars().enumerate() {
            for (j, c2) in s.chars().rev().enumerate() {
                if c1 == c2 {
                    if i == 0 || j == 0 {
                        arr[i][j] = 1;
                    } else {
                        arr[i][j] = 1 + arr[i - 1][j - 1];
                    }
                    if max_len < arr[i][j] {
                        if len - 1 - j + arr[i][j] - 1 == i {
                            max_len = arr[i][j];
                            max_end = i;
                        }
                    }
                }
            }
        }
        (&s[max_end + 1 - max_len..max_end + 1]).to_string()
    }

    pub fn longest_substring_length(str1: &str, str2: &str) -> usize {
        let len = str1.len();
        let mut max_len = 0;
        let mut arr: Vec<Vec<usize>> = vec![vec![0; len]; len];
        for (i, c1) in str1.chars().enumerate() {
            for (j, c2) in str2.chars().enumerate() {
                if c1 == c2 {
                    if i == 0 || j == 0 {
                        arr[i][j] = 1;
                    } else {
                        arr[i][j] = 1 + arr[i - 1][j - 1];
                    }
                    max_len = max_len.max(arr[i][j])
                }
            }
        }
        max_len
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution {};
        assert_eq!(
            Solution::longest_palindrome("babad".into()),
            "bab".to_string()
        );
        assert_eq!(
            Solution::longest_substring_length("acbcbcef", "abcbced"),
            5
        );
    }
}
