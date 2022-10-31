pub enum BoxList {
    Cons(i32, Box<BoxList>),
    Nil,
}

use std::rc::Rc;
#[derive(Debug)]
pub enum List {
    Cons(i32, Rc<List>),
    Nil,
}

#[cfg(test)]
mod test {
    #[test]
    fn rc_ptr_test() {
        /* use super::BoxList::{Cons, Nil};
        let a = Cons(3, Box::new(Cons(10, Box::new(Nil))));
        let b = Cons(1, Box::new(a)); // value used here after move
        let c = Cons(1, Box::new(a)); // use of moved value: `a` */

        use super::List::{Cons, Nil};
        use std::rc::Rc;
        let a = Rc::new(Cons(3, Rc::new(Cons(10, Rc::new(Nil)))));
        println!("a count after creating: {}", Rc::strong_count(&a));
        let b = Cons(1, Rc::clone(&a));
        println!("a count after b: {}", Rc::strong_count(&a));
        {
            let c = Cons(1, Rc::clone(&a));
            println!("a count after c: {}", Rc::strong_count(&a));
        }
        println!("a count after c out scope: {}", Rc::strong_count(&a));
    }
}
