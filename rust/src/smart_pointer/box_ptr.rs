#[derive(Debug)]
pub enum List {
    Cons(i32, Box<List>),
    Nil,
}

/* enum List {
    Cons(i32, List), // Error: recursive type `List` has infinite size recursive type has infinite size
    Nil,
} */

#[cfg(test)]
mod test {
    use super::List::{Cons, Nil};
    #[test]
    fn test() {
        let list = Cons(2, Box::new(Cons(3, Box::new(Cons(4, Box::new(Nil))))));
        println!("{:?}", list);

        // normal pointer
        let a = 2;
        let b = &a;

        assert_eq!(a, *b);
        assert_eq!(&a, b);

        // box pointer
        let a = 3;
        let b = Box::new(a);

        assert_eq!(a, *b);

        // normal pointer mut
        let mut a = 3;
        let b = &mut a;
        *b = 4;
        println!("a after: {}", a);
        // let mut c = 3;
        // b = &mut c; // cannot assign twice to immutable variable `b`

        // box pointer mut?
        let mut a = 2;
        let b = Box::new(&mut a); // box point to mutable reference
        println!("b: {:?}", b);
        **b = 3;

        /* let mut c = 3;
         *b = &mut c; // let box point to another mutable reference */
        println!("a after: {:?}", a);
    }
}
