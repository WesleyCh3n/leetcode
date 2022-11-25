impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        Self::recursive(&coins, amount)
    }

    pub fn recursive(coins: &Vec<i32>, amount: i32) -> i32 {
        if amount == 0 {
            return 0;
        }
        if amount < 0 {
            return -1;
        }
        let mut result = i32::MAX;
        for coin in coins {
            let sub_problem = Self::recursive(&coins, amount - coin);
            if sub_problem == -1 {
                continue;
            }
            result = (sub_problem + 1).min(result);
        }
        if result == i32::MAX {
            -1
        } else {
            result
        }
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution {};
        assert_eq!(Solution::coin_change(vec![1, 2, 5], 11), 3);
        assert_eq!(Solution::coin_change(vec![2], 3), -1);
        assert_eq!(Solution::coin_change(vec![1], 0), 0);
    }
}
