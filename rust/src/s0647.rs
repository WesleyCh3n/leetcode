pub struct Solution {}

impl Solution {
    pub fn count_substrings(s: String) -> i32 {
        let chars = s.as_bytes();
        let mut cnt = 0;
        for i in 0..s.len() {
            cnt += Self::count_pali(i as i32, i as i32, chars);
            cnt += Self::count_pali(i as i32, i as i32 + 1, chars);
        }
        cnt
    }
    fn count_pali(mut l: i32, mut r: i32, chars: &[u8]) -> i32 {
        let mut cnt = 0;
        while l >= 0
            && r < chars.len() as i32
            && chars[l as usize] == chars[r as usize]
        {
            l -= 1;
            r += 1;
            cnt += 1;
        }
        cnt
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        assert_eq!(Solution::count_substrings("abc".to_string()), 3);
        assert_eq!(Solution::count_substrings("aaa".to_string()), 6);
    }
}
