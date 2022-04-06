pub struct Solution {}

impl Solution {
    pub fn contains_duplicate(mut nums: Vec<i32>) -> bool {
        nums.sort();
        for i in 0..nums.len() - 1 {
            if nums[i] == nums[i + 1] {
                return true;
            }
        }
        false
    }
}

fn main() {
    let v = vec![1,1,1,3,3,4,3,2,4,2];
    println!("{}", Solution::contains_duplicate(v));
}
