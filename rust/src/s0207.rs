pub struct Solution {}

#[derive(Clone, Copy)]
enum Status {
    Todo,
    InProgress,
    Done,
}

impl Solution {
    pub fn can_finish(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> bool {
        let graph = Self::build_graph(num_courses as usize, prerequisites);
        let mut status = vec![Status::Todo; num_courses as usize];
        let mut has_cycle = false;
        for course in 0..num_courses - 1 {
            Self::dfs(&graph, course as usize, &mut status, &mut has_cycle);
            if has_cycle == true {
                return false;
            }
        }
        !has_cycle
    }

    fn dfs(
        graph: &Vec<Vec<i32>>,
        v: usize,
        status: &mut Vec<Status>,
        has_cycle: &mut bool,
    ) {
        match status[v] {
            Status::Done => return,
            Status::InProgress => {
                *has_cycle = true;
                return;
            }
            Status::Todo => {
                status[v] = Status::InProgress;
                for &i in graph[v].iter() {
                    Self::dfs(graph, i as usize, status, has_cycle);
                }
                status[v] = Status::Done;
            }
        }
    }
    fn build_graph(
        num_courses: usize,
        prerequisites: Vec<Vec<i32>>,
    ) -> Vec<Vec<i32>> {
        let mut graph = vec![Vec::new(); num_courses];
        for edge in prerequisites.into_iter() {
            graph[edge[0] as usize].push(edge[1]); // because prerequisites[i].len == 2
        }
        graph
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution {};
        assert_eq!(Solution::can_finish(2, vec![vec![0, 1]]), true);
        assert_eq!(
            Solution::can_finish(2, vec![[0, 1].to_vec(), [1, 0].to_vec()]),
            false
        );
    }
}
