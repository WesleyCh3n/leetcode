pub struct Solution {}

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        use std::collections::HashMap;
        let mut map: HashMap<i32, u32> = HashMap::new();
        for &num in nums.iter() {
            let cnt = map.entry(num).or_insert(0);
            *cnt += 1;
        }
        let mut freq: Vec<Vec<i32>> = vec![Vec::new(); nums.len()];
        for (&k, &v) in map.iter() {
            freq[v as usize].push(k);
        }
        let mut result: Vec<i32> = vec![];
        for v in freq.into_iter().rev() {
            for a in v.into_iter() {
                if result.len() == k as usize {
                    break;
                }
                result.push(a);
            }
        }
        println!("{:?}", result);
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution::top_k_frequent(vec![1, 1, 1, 2, 2, 3], 2);
    }
}
