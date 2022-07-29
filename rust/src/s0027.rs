// Definition for singly-linked list.
pub struct Solution {}

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        while let Some(index) = nums.iter().position(|v| *v == val) {
            nums.remove(index);
        }
        // built-in func
        // nums.retain(|&x| x != val);

        nums.len() as i32
    }
    pub fn remove_element_2(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut w = 0;
        for i in 0..nums.len() {
            if nums[i] != val {
                nums.swap(w, i);
                w += 1;
            }
        }
        w as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        // Solution::remove_element(&mut vec![1,2,3], 2);
        Solution::remove_element(&mut vec![3,2,2,3], 3);
    }
}
