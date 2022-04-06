struct Solution {}

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut sum = nums[0];
        let mut max_val = nums[0];
        for i in 1..nums.len() {
            sum = nums[i].max(sum + nums[i]);
            max_val = max_val.max(sum);
        }
        max_val
    }
}

fn main() {
    let v = vec![-2,1,-3,4,-1,2,1,-5,4];
    println!("{}", Solution::max_sub_array(v));
}
