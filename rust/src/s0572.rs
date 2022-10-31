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
pub struct Solution {}

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn is_subtree(
        root: Option<Rc<RefCell<TreeNode>>>,
        sub_root: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        Self::is_subtree_ref(&root, &sub_root)
    }

    pub fn is_subtree_ref(
        root: &Option<Rc<RefCell<TreeNode>>>,
        sub_root: &Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        if Self::is_same_tree(&root, &sub_root) {
            return true;
        }
        if let Some(root) = &root {
            let root = root.borrow();
            Self::is_subtree_ref(&root.left, sub_root)
                || Self::is_subtree_ref(&root.right, sub_root)
        } else {
            false
        }
    }

    pub fn is_same_tree(
        p: &Option<Rc<RefCell<TreeNode>>>,
        q: &Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        if let (Some(p), Some(q)) = (p, q) {
            let (p, q) = (p.borrow(), q.borrow());
            p.val == q.val
                && Self::is_same_tree(&p.left, &q.left)
                && Self::is_same_tree(&p.right, &q.right)
        } else {
            p == &None && q == &None
        }
    }
}
