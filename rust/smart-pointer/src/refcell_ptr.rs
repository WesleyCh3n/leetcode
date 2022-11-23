// use std::{cell::RefCell, rc::Rc};

pub trait Messenger {
    fn send(&self, msg: &str);
}

pub struct LimitTracker<'a, T: Messenger> {
    messenger: &'a T,
    value: usize,
    max: usize,
}

impl<'a, T> LimitTracker<'a, T>
where
    T: Messenger,
{
    pub fn new(messenger: &'a T, max: usize) -> Self {
        LimitTracker {
            messenger,
            value: 0,
            max,
        }
    }

    pub fn set_value(&mut self, value: usize) {
        self.value = value;

        let percentage_of_max = self.value as f64 / self.max as f64;

        if percentage_of_max >= 1.0 {
            self.messenger.send("Error: You are over your quota!");
        } else if percentage_of_max >= 0.9 {
            self.messenger
                .send("Urgent warning: You've used up over 90% of your quota!");
        } else if percentage_of_max >= 0.75 {
            self.messenger
                .send("Warning: You've used up over 75% of your quota!");
        }
    }
}

#[cfg(test)]
mod test {
    use super::*;
    use std::{cell::RefCell, rc::Rc};

    struct MockMessenger {
        sent_messages: RefCell<Vec<String>>,
    }

    impl MockMessenger {
        pub fn new() -> Self {
            Self {
                sent_messages: RefCell::new(vec![]),
            }
        }
    }

    impl Messenger for MockMessenger {
        fn send(&self, msg: &str) {
            self.sent_messages.borrow_mut().push(String::from(msg));

            // this will panic at runtime
            /* let mut one_borrow = self.sent_messages.borrow_mut();
            let mut two_borrow = self.sent_messages.borrow_mut();

            one_borrow.push(String::from(msg));
            two_borrow.push(String::from(msg)); */
        }
    }

    #[test]
    fn it_sends_an_over_75_percent_warning_message() {
        let mock_messenger = MockMessenger::new();
        let mut limit_tracker = LimitTracker::new(&mock_messenger, 100);

        limit_tracker.set_value(80);

        assert_eq!(mock_messenger.sent_messages.borrow().len(), 1);
    }

    #[test]
    fn refcell_test() {
        let mut a = 12;
        let b = RefCell::new(&mut a);
        **b.borrow_mut() = 3;
        println!("a after RefCell: {}", a);
    }

    #[derive(Debug)]
    enum List {
        Cons(i32, RefCell<Rc<List>>),
        Nil,
    }

    impl List {
        fn tail(&self) -> Option<&RefCell<Rc<Self>>> {
            match self {
                Self::Cons(_, item) => Some(item),
                Self::Nil => None,
            }
        }
    }

    #[test]
    fn ref_cycle_test() {
        use List::{Cons, Nil};

        let a = Rc::new(Cons(1, RefCell::new(Rc::new(Nil))));
        println!("{:?}", a.tail());
        let b = Rc::new(Cons(2, RefCell::new(a.clone())));
        println!("{:?}", b.tail());

        if let Some(link) = a.tail() {
            *link.borrow_mut() = b.clone();
        }
        // stack overflow
    }
}
