use std::{
    cell::RefCell,
    rc::{Rc, Weak},
};

#[derive(Debug)]
pub struct Node {
    pub value: i32,
    pub parent: RefCell<Weak<Node>>,
    pub children: RefCell<Vec<Rc<Node>>>,
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn rc_weak_test() {
        let leaf = Rc::new(Node {
            value: 1,
            parent: RefCell::new(Weak::new()),
            children: RefCell::new(vec![]),
        });
        println!("leaf parent: {:?}", leaf.parent.borrow().upgrade());

        let parent = Rc::new(Node {
            value: 12,
            parent: RefCell::new(Weak::new()),
            children: RefCell::new(vec![leaf.clone()]),
        });

        *leaf.parent.borrow_mut() = Rc::downgrade(&parent);

        println!("leaf parent: {:#?}", leaf.parent.borrow().upgrade());
    }
}
