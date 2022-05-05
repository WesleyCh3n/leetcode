// Definition for singly-linked list.
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
    pub fn merge_two_lists(
        mut list1: Option<Box<ListNode>>,
        mut list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut head = Box::new(ListNode::new(0));
        let mut curr = head.as_mut();

        while let (Some(h1), Some(h2)) = (list1.as_mut(), list2.as_mut()) {
            if h1.val < h2.val {
                let next_h1 = h1.next.take();
                curr.next = list1;
                list1 = next_h1;
            } else {
                let next_h2 = h2.next.take();
                curr.next = list2;
                list2 = next_h2;
            }
            curr = curr.next.as_mut().unwrap();
        }

        if list1.is_none() {
            curr.next = list2;
        } else {
            curr.next = list1;
        }

        head.next
    }

    pub fn merge_two_lists_recursive(
        list1: Option<Box<ListNode>>,
        list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        match (list1, list2) {
            (None, None) => None,
            (Some(l), None) | (None, Some(l)) => Some(l),
            (Some(mut l1), Some(mut l2)) => {
                if l1.val < l2.val {
                    l1.next =
                        Solution::merge_two_lists_recursive(l1.next, Some(l2));
                    return Some(l1);
                } else {
                    l2.next =
                        Solution::merge_two_lists_recursive(Some(l1), l2.next);
                    return Some(l2);
                }
            }
        }
    }
}
