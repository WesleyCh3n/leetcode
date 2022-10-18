use std::collections::HashMap;
pub struct Solution {}

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut map: HashMap<String, usize> = HashMap::new();
        let mut result = Vec::new();
        for s in strs {
            // create hash key
            // find if hash key in map
            // -> no: insert hash key in map, value is result vec len - 1
            // -> yes: get value from map, insert s to vec[value]
            let key = Self::get_key(&s);
            if !map.contains_key(&key) {
                result.push(vec![s]);
                map.insert(key, result.len() - 1);
            } else {
                result[map[&key]].push(s);
            }
        }
        result
    }

    fn get_key(s: &String) -> String {
        let mut chars: Vec<char> = s.chars().collect();
        chars.sort();
        chars.iter().collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution {};
    }
}
