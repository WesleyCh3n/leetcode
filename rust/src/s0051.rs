pub struct Solution {}

impl Solution {
    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
        let mut board: Vec<String> = vec![".".repeat(n as usize); n as usize];
        let mut results: Vec<Vec<String>> = Vec::new();
        Self::backtrack(&mut board, 0, &mut results);
        println!("results {:?}", results);
        results
    }
    pub fn backtrack(
        board: &mut Vec<String>,
        row: usize,
        results: &mut Vec<Vec<String>>,
    ) {
        if row == board.len() {
            results.push(board.clone());
            return;
        }
        for col in 0..board[row].len() {
            if !Self::is_valid(row, col, &board) {
                continue;
            }
            board[row].replace_range(col..col + 1, "Q");
            Self::backtrack(board, row + 1, results);
            board[row].replace_range(col..col + 1, ".");
        }
    }
    pub fn is_valid(row: usize, col: usize, board: &Vec<String>) -> bool {
        // check upper column
        for i in 0..=row {
            if board[i].as_bytes()[col] == 'Q' as u8 {
                return false;
            }
        }
        // check left diagonal
        if row > 0 && col > 0 {
            for (i, j) in (0..=row - 1).rev().zip((0..=col - 1).rev()) {
                if board[i].as_bytes()[j] == 'Q' as u8 {
                    return false;
                }
            }
        }
        // check right diagonal
        if row > 0 {
            for (i, j) in (0..=row - 1).rev().zip(col + 1..board.len()) {
                if board[i].as_bytes()[j] == 'Q' as u8 {
                    return false;
                }
            }
        }
        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution {};
        Solution::solve_n_queens(4);
        // assert_eq!(Solution::solve_n_queen(),);
    }
}
