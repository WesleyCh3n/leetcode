pub struct Solution {}

impl Solution {
    pub fn num_decodings(s: String) -> i32 {
        let chars: Vec<char> = s.chars().collect();
        Self::decode(&chars, 0) as i32
    }
    // 1. recursion: O(2^n)
    fn decode(num: &[char], index: usize) -> u32 {
        // if len == 0
        //    return 1
        // if one char valid
        //    send num[1..]
        // if two chars valid
        //    send num[2..]
        if index == num.len() {
            return 1;
        }
        let mut result = 0;
        if num[index] != '0' {
            result += Self::decode(num, index + 1);
        }
        if index < num.len() - 1
            && (num[index] == '1'
                || (num[index] == '2' && num[index + 1] < '7'))
        {
            result += Self::decode(num, index + 2)
        }
        result
    }
}

// Top-down Memoization
pub struct S2 {}
impl S2 {
    pub fn num_decodings(s: String) -> i32 {
        let chars: Vec<char> = s.chars().collect();
        let mut mem = vec![-1; chars.len() + 1];
        Self::decode(&chars, 0, &mut mem) as i32
    }
    fn decode(num: &[char], index: usize, mem: &mut Vec<i32>) -> u32 {
        if mem[index] != -1 {
            return mem[index] as u32;
        }
        if index == num.len() {
            return 1;
        }
        let mut result = 0;
        if num[index] != '0' {
            result += Self::decode(num, index + 1, mem);
        }
        if index < num.len() - 1
            && (num[index] == '1'
                || (num[index] == '2' && num[index + 1] < '7'))
        {
            result += Self::decode(num, index + 2, mem)
        }
        mem[index] = result as i32;
        mem[index] as u32
    }
}

// Bottom-up Memoization
pub struct S3 {}
impl S3 {
    pub fn num_decodings(s: String) -> i32 {
        let chars: Vec<char> = s.chars().collect();
        // mem[i]: number of ways to decode len s
        let mut mem = vec![0; chars.len() + 1];
        mem[0] = 1;
        mem[1] = if chars[0] == '0' { 0 } else { 1 };
        for i in 2..=chars.len() {
            let curr = &chars[i - 1];
            let prev = &chars[i - 2];
            if curr != &'0' {
                mem[i] += mem[i - 1];
            }
            if prev == &'1' || (prev == &'2' && curr < &'7') {
                mem[i] += mem[i - 2];
            }
        }
        mem[s.len()]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        assert_eq!(Solution::num_decodings("12".to_string()), 2);
        assert_eq!(Solution::num_decodings("226".to_string()), 3);
        assert_eq!(Solution::num_decodings("06".to_string()), 0);
        assert_eq!(Solution::num_decodings("27".to_string()), 1);
        // NOTE: Time exceeed
        // assert!(
        //     Solution::num_decodings(
        //         "111111111111111111111111111111111111111111111".to_string()
        //     ) == 1836311903
        // );
        assert_eq!(S2::num_decodings("12".to_string()), 2);
        assert_eq!(S2::num_decodings("226".to_string()), 3);
        assert_eq!(S2::num_decodings("06".to_string()), 0);
        assert_eq!(S2::num_decodings("27".to_string()), 1);
        assert_eq!(
            S2::num_decodings(
                "111111111111111111111111111111111111111111111".to_string()
            ),
            1836311903
        );

        assert_eq!(S3::num_decodings("12".to_string()), 2);
        assert_eq!(S3::num_decodings("226".to_string()), 3);
        assert_eq!(S3::num_decodings("06".to_string()), 0);
        assert_eq!(S3::num_decodings("27".to_string()), 1);
        assert_eq!(
            S3::num_decodings(
                "111111111111111111111111111111111111111111111".to_string()
            ),
            1836311903
        );
    }
}
