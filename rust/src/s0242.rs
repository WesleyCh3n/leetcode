use std::collections::HashMap;

pub struct Solution {}

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }
        let mut map: HashMap<char, i32> = HashMap::new();
        for (a, b) in s.chars().zip(t.chars()) {
            let cnt = map.entry(a).or_insert(0);
            *cnt += 1;
            let cnt = map.entry(b).or_insert(0);
            *cnt -= 1;
        }
        for (_, v) in map {
            if v != 0 {
                return false;
            }
        }
        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn contains_duplicate_test() {}
}
