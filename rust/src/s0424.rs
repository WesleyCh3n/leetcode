pub struct Solution {}

impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let mut counts: [usize; 26] = [0; 26];
        let (mut max_length, mut max_count) = (0, 0);
        let s: Vec<char> = s.chars().collect();
        let (mut left, mut right) = (0, 0);
        while right < s.len() {
            counts[s[right] as usize - 'A' as usize] += 1;
            max_count = max_count.max(counts[s[right] as usize - 'A' as usize]);
            if right - left + 1 - max_count > k as usize {
                counts[s[left] as usize - 'A' as usize] -= 1;
                left += 1;
            }
            max_length = max_length.max(right - left + 1);
            right += 1;
        }
        max_length as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        assert_eq!(Solution::character_replacement("ABAB".to_string(), 2), 4);
        assert_eq!(
            Solution::character_replacement("AABABBA".to_string(), 1),
            4
        );
    }
}
