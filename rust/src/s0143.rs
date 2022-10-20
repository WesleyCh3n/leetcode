pub struct Solution {}

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

impl Solution {
    pub fn reorder_list(head: &mut Option<Box<ListNode>>) {
        if head.is_none() {
            return;
        }
        let mut mid = 0;
        let (mut slow, mut fast) = (head.as_ref(), head.as_ref());
        while fast.is_some() && fast.unwrap().next.is_some() {
            fast = fast.unwrap().next.as_ref().unwrap().next.as_ref();
            slow = slow.unwrap().next.as_ref();
            mid += 1;
        }

        let mut node = head.as_mut();
        for _ in 0..mid {
            node = node.unwrap().next.as_mut();
        }

        let l2 = node.unwrap().next.take();
        let mut prev: Option<Box<ListNode>> = None;
        let mut next: Option<Box<ListNode>> = l2;
        while let Some(mut node) = next {
            next = node.next.take();
            node.next = prev;
            prev = Some(node);
        }
        let mut l2_rev = prev;

        // TODO:
        while let (Some(h1), Some(h2)) = (head.as_mut(), l2_rev.as_mut()) {
            let next_h1 = h1.next.take();
            h1.next = l2_rev;
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
