pub struct Solution {}

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut v = vec![];
        for c in s.chars() {
            match c {
                '(' => v.push(')'),
                '[' => v.push(']'),
                '{' => v.push('}'),
                ')' | ']' | '}' if v.pop() != Some(c) => return false,
                _ => (),
            }
        }
        v.is_empty()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        assert_eq!(Solution::is_valid("()[]{}".to_string()), true);
        assert_eq!(Solution::is_valid("(}".to_string()), false);
        assert_eq!(Solution::is_valid("()".to_string()), true);
    }
}
