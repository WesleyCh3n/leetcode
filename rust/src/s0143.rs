pub struct Solution {}
use rust_leetcode::ListNode;

impl Solution {
    pub fn reorder_list(head: &mut Option<Box<ListNode>>) {
        if head.is_none() {
            return;
        }
        // slow fast pointer find mid len
        let mut mid = 0;
        let (mut slow, mut fast) = (head.as_ref(), head.as_ref());
        while fast.is_some() && fast.unwrap().next.is_some() {
            fast = fast.unwrap().next.as_ref().unwrap().next.as_ref();
            slow = slow.unwrap().next.as_ref();
            mid += 1;
        }

        // find mid list start
        let mut curr = head.as_mut();
        for _ in 0..mid {
            curr = curr.unwrap().next.as_mut();
        }

        // reverse list leetcode: 206
        let l2 = curr.unwrap().next.take();
        let mut prev: Option<Box<ListNode>> = None;
        let mut next: Option<Box<ListNode>> = l2;
        while let Some(mut node) = next {
            next = node.next.take();
            node.next = prev;
            prev = Some(node);
        }

        // merge two list
        let mut h2_next = prev;
        let mut curr = head.as_mut().unwrap();
        while h2_next.is_some() {
            let mut node = h2_next.take().unwrap();
            h2_next = node.next;

            node.next = curr.next.take();
            curr.next = Some(node);
            curr = curr.next.as_mut().unwrap().next.as_mut().unwrap();
        }
    }

    pub fn reorder_list_deque(head: &mut Option<Box<ListNode>>) {
        let mut buf = std::collections::VecDeque::with_capacity(5 * 10 ^ 4);

        if let Some(root) = head.as_mut() {
            let cur = root.next.take();
            buf.push_back(cur);
            while let Some(node) = buf.back_mut().unwrap() {
                let next = node.next.take();
                if next.is_some() {
                    buf.push_back(next);
                } else {
                    break;
                }
            }
        }

        let mut cur = head.as_mut().unwrap();
        while buf.len() > 0 {
            if let Some(node) = buf.pop_back() {
                cur.next = node;
                if buf.len() > 0 {
                    cur = cur.next.as_mut().unwrap();
                } else {
                    break;
                }
            }
            if let Some(node) = buf.pop_front() {
                cur.next = node;
                cur = cur.next.as_mut().unwrap();
            }
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
