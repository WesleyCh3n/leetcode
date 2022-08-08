pub struct Solution {}

impl Solution {
    /// This is doc document
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        if nums.len() <= 1 {
            return nums.len() as i32;
        }
        let most_appear_times = 2;
        let mut tail = most_appear_times;
        for i in most_appear_times..nums.len() {
            if nums[i] != nums[tail - most_appear_times] {
                nums[tail] = nums[i];
                tail += 1;
            }
        }
        println!("{:?}", nums);
        println!("{}", tail);
        tail as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution::remove_duplicates(&mut vec![0,0,1,1,1,2,2,3,3,4]);
    }
}
