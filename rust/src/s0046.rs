pub struct Solution {}

impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let mut track = Vec::new();
        let mut used = vec![false; nums.len()];

        Self::backtrack(&nums, &mut track, &mut used, &mut result);
        result
    }

    fn backtrack(
        nums: &Vec<i32>,
        track: &mut Vec<i32>,
        used: &mut Vec<bool>,
        result: &mut Vec<Vec<i32>>,
    ) {
        if track.len() == nums.len() {
            result.push(track.clone());
        }
        for i in 0..nums.len() {
            if used[i] {
                continue;
            }
            track.push(nums[i]);
            used[i] = true;
            Self::backtrack(nums, track, used, result);
            track.pop();
            used[i] = false;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution {};
        assert_eq!(
            Solution::permute(vec![1, 2, 3]),
            vec![
                [1, 2, 3],
                [1, 3, 2],
                [2, 1, 3],
                [2, 3, 1],
                [3, 1, 2],
                [3, 2, 1]
            ]
        );
    }
}
