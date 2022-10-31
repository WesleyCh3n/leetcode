pub struct Solution {}
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        use std::collections::VecDeque;
        let mut q = VecDeque::new();
        if let Some(node) = root {
            q.push_back(node);
        } else {
            return Vec::new();
        }

        let mut result = Vec::new();
        while !q.is_empty() {
            let mut curr_level = Vec::new();

            let mut level_cnt = q.len();
            while let Some(node) = q.pop_front() {
                let mut node = node.borrow_mut();
                if let Some(left) = node.left.take() {
                    q.push_back(left);
                }
                if let Some(right) = node.right.take() {
                    q.push_back(right);
                }
                curr_level.push(node.val);

                level_cnt -= 1;
                if level_cnt == 0 {
                    break;
                }
            }
            result.push(curr_level);
        }
        result
    }
}
