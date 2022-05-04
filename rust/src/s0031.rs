pub struct Solution {}

impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
        let n = nums.len();
        if n <= 1 {
            return;
        }
        let (mut i, mut j) = (n - 1, n - 1);
        while i > 0 && nums[i - 1] >= nums[i] {
            i -= 1;
        }
        if i == 0 {
            nums.reverse();
            return;
        }
        while j >= i && nums[i - 1] >= nums[j] {
            j -= 1;
        }
        nums.swap(i - 1, j);
        nums[i..].reverse();
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        let mut v = vec![5, 4, 7, 5, 3, 2];
        Solution::next_permutation(&mut v);
        assert_eq!(v, vec![5, 5, 2, 3, 4, 7]);
        let mut v = vec![4, 3, 2, 1];
        Solution::next_permutation(&mut v);
        assert_eq!(v, vec![1, 2, 3, 4]);
        let mut v = vec![1, 3, 2];
        Solution::next_permutation(&mut v);
        assert_eq!(v, vec![2, 1, 3]);
    }
}
