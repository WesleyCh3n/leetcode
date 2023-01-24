impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        Self::dp_bottom_up(&coins, amount)
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

    pub fn dp_top_down(coins: &Vec<i32>, amount: i32, memo: &mut [i32]) -> i32 {
        if amount == 0 {
            return 0;
        }
        if amount < 0 {
            return -1;
        }
        if memo[amount as usize] != -2 {
            return memo[amount as usize];
        }
        let mut result = i32::MAX;
        for coin in coins {
            let sub_problem = Self::recursive(&coins, amount - coin);
            if sub_problem == -1 {
                continue;
            }
            result = (sub_problem + 1).min(result);
        }
        memo[amount as usize] = if result == i32::MAX { -1 } else { result };
        memo[amount as usize]
    }

    pub fn dp_bottom_up(coins: &Vec<i32>, amount: i32) -> i32 {
        let mut dp = vec![amount + 1; amount as usize + 1];

        dp[0] = 0;
        for i in 0..dp.len() {
            for &coin in coins {
                if i as i32 - coin < 0 {
                    continue;
                }
                dp[i] = dp[i].min(dp[i - coin as usize] + 1);
            }
        }
        if dp[amount as usize] == amount + 1 {
            -1
        } else {
            dp[amount as usize]
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

        let mut memo = vec![-2; 11 + 1];
        assert_eq!(Solution::dp_top_down(&vec![1, 2, 5], 11, &mut memo), 3);
        let mut memo = vec![-2; 3 + 1];
        assert_eq!(Solution::dp_top_down(&vec![2], 3, &mut memo), -1);
        let mut memo = vec![-2; 0 + 1];
        assert_eq!(Solution::dp_top_down(&vec![1], 0, &mut memo), 0);

        assert_eq!(Solution::dp_bottom_up(&vec![1, 2, 5], 11), 3);
        assert_eq!(Solution::dp_bottom_up(&vec![2], 3), -1);
        assert_eq!(Solution::dp_bottom_up(&vec![1], 0), 0);
    }
}
