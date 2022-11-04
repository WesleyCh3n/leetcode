use std::{cell::RefCell, rc::Rc};

use rust_leetcode::TreeNode;

impl Solution {
    pub fn kth_smallest(
        root: Option<Rc<RefCell<TreeNode>>>,
        mut k: i32,
    ) -> i32 {
        let mut answer: i32 = 0;
        Self::in_order(&root, &mut k, &mut answer);
        answer
    }

    fn in_order(
        root: &Option<Rc<RefCell<TreeNode>>>,
        k: &mut i32,
        result: &mut i32,
    ) {
        if let Some(node) = root {
            let node = node.borrow();
            Self::in_order(&node.left, k, result);
            *k -= 1;
            if *k == 0 {
                *result = node.val;
                return;
            }
            Self::in_order(&node.right, k, result);
        } else {
            return;
        }
    }
    fn in_order_stack(
        root: &Option<Rc<RefCell<TreeNode>>>,
        k: &mut i32,
        result: &mut i32,
    ) {
        todo!()
        // let s = vec![];
        // while s.is_empty() || node.left {}
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    use super::*;
    use rust_leetcode::btree;

    #[test]
    fn test() {
        Solution {};
        assert_eq!(1, Solution::kth_smallest(btree![3, 1, 4, null, 2], 1));
        assert_eq!(
            3,
            Solution::kth_smallest(btree![5, 3, 6, 2, 4, null, null, 1], 3)
        );
    }
}
