// Definition for a binary tree node.
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
    pub fn lowest_common_ancestor(
        root: Option<Rc<RefCell<TreeNode>>>,
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let p_val = p.clone().unwrap().borrow().val;
        let q_val = q.clone().unwrap().borrow().val;
        if let Some(node) = root.clone() {
            let mut node = node.borrow_mut();
            if p_val < node.val && q_val < node.val {
                return Self::lowest_common_ancestor(node.left.take(), p, q);
            } else if p_val > node.val && q_val > node.val {
                return Self::lowest_common_ancestor(node.right.take(), p, q);
            } else {
                return root;
            }
        } else {
            None
        }
    }
}
