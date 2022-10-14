pub struct Solution {}

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        use std::collections::HashSet;
        let mut set: HashSet<char> = HashSet::new();
        let (mut i, mut j) = (0, 0);
        let mut result = 0;
        let s = s.chars().into_iter().collect::<Vec<char>>();
        while j < s.len() {
            if !set.contains(&s[j]) {
                set.insert(s[j]);
                result = std::cmp::max(result, j - i + 1);
                j += 1;
            } else {
                set.remove(&s[i]);
                i += 1;
            }
        }
        result as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        assert_eq!(
            Solution::length_of_longest_substring("abcabcbb".to_string()),
            3
        );
    }
}
