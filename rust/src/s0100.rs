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
    pub fn is_same_tree(
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        if let (Some(p_node), Some(q_node)) = (&p, &q) {
            let mut p_borrow = p_node.borrow_mut();
            let mut q_borrow = q_node.borrow_mut();
            p_borrow.val == q_borrow.val
                && Self::is_same_tree(
                    p_borrow.left.take(),
                    q_borrow.left.take(),
                )
                && Self::is_same_tree(
                    p_borrow.right.take(),
                    q_borrow.right.take(),
                )
        } else {
            p == None && q == None
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        Solution {};
    }
}
