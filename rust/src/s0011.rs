pub struct Solution {}

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let (mut left, mut right) = (0, height.len() - 1);
        let mut result = 0;
        while left < right {
            let area = std::cmp::min(height[left], height[right])
                * (right as i32 - left as i32);
            result = std::cmp::max(result, area);
            // NOTE: smaller one can saftlly remove because it can't support more water
            if height[left] <= height[right] {
                left += 1;
            } else {
                right -= 1;
            }
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        println!("{}", Solution::max_area(vec![1, 8, 6, 2, 5, 4, 8, 3, 7]));
    }
}
