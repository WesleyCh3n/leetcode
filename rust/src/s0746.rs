pub struct Solution {}

impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        // You are given an integer array cost where cost[i] is the cost of ith
        // step on a staircase. Once you pay the cost, you can either climb one or two steps.
        //
        // You can either start from the step with index 0, or the step with index 1.
        //
        // Return the minimum cost to reach the top of the floor.
        // let mut result = vec![0; cost.len() + 1];
        // result[cost.len()]
        std::cmp::min(
            Solution::top_down(&cost, cost.len() - 1),
            Solution::top_down(&cost, cost.len() - 2),
        )
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
