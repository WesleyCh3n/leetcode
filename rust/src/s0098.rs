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
static mut PREV: i64 = i64::MIN;
impl Solution {
    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        // unsafe { PREV = i64::MIN };
        // Self::in_order(&root)
        Self::is_between(&root, None, None)
    }
    pub fn in_order(root: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        if let Some(root_node) = root {
            let node = root_node.borrow();
            if !Self::in_order(&node.left) {
                return false;
            }
            unsafe {
                println!("{:?}, {}", node, PREV);
                if node.val as i64 <= PREV {
                    return false;
                }
                PREV = node.val as i64;
            }
            if !Self::in_order(&node.right) {
                return false;
            }
            return true;
        } else {
            return true;
        }
    }
    pub fn is_between(
        root: &Option<Rc<RefCell<TreeNode>>>,
        min: Option<i32>,
        max: Option<i32>,
    ) -> bool {
        match root {
            Some(root) => {
                //
                let node = root.borrow();

                if !min.is_none() && min.unwrap() >= node.val {
                    return false;
                }
                if !max.is_none() && max.unwrap() <= node.val {
                    return false;
                }
                return Self::is_between(&node.left, min, Some(node.val))
                    && Self::is_between(&node.right, Some(node.val), max);
            }
            None => true,
        }
    }
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn test() {
        let a = Some(Rc::new(RefCell::new(TreeNode::new(0))));
        println!("bool: {}", Solution::is_valid_bst(a));
    }
}
