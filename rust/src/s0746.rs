pub struct Solution {}

impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        // You are given an integer array cost where cost[i] is the cost of ith
        // step on a staircase. Once you pay the cost, you can either climb one or two steps.
        //
        // You can either start from the step with index 0, or the step with index 1.
        //
        // Return the minimum cost to reach the top of the floor.

        // std::cmp::min(
        //     Solution::top_down(&cost, cost.len() - 1),
        //     Solution::top_down(&cost, cost.len() - 2),
        // );

        Self::bottom_up(&cost)
    }
    pub fn top_down(cost: &Vec<i32>, n: usize) -> i32 {
        if n == 0 || n == 1 {
            return cost[n];
        }
        cost[n]
            + std::cmp::min(
                Solution::top_down(cost, n - 1),
                Solution::top_down(cost, n - 2),
            )
    }
    pub fn bottom_up(cost: &Vec<i32>) -> i32 {
        let n = cost.len();
        let mut dp = vec![0; n];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for i in 2..n {
            dp[i] = cost[i] + std::cmp::min(dp[i - 1], dp[i - 2])
        }
        std::cmp::min(dp[n - 1], dp[n - 2])
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        assert_eq!(Solution::min_cost_climbing_stairs(vec![10, 15, 20]), 15);
        assert_eq!(
            Solution::min_cost_climbing_stairs(vec![
                1, 100, 1, 1, 1, 100, 1, 1, 100, 1
            ]),
            6
        );
    }
}
