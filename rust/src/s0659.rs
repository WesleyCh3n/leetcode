pub struct Solution {}

impl Solution {
    pub fn encode(strs: Vec<String>) -> String {
        let mut s = String::new();
        for w in strs.into_iter() {
            s.push_str(format!("{}#{}", w.len(), w).as_str());
        }
        s
    }
    pub fn decode(s: String) -> Vec<String> {
        let mut strs: Vec<String> = Vec::new();

        let mut i = 0;
        while i < s.len() {
            let mut j = i;
            while s.chars().nth(j) != Some('#') {
                j += 1;
            }
            let len = s[i..j].parse::<usize>().unwrap();
            strs.push(s[j + 1..j + 1 + len].to_string());
            i = j + 1 + len;
        }
        strs
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        let s = Solution::encode(vec!["1".into(), "2".into()]);
        println!("{}", s);
        println!("{:?}", Solution::decode(s));
    }
}
