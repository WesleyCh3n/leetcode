#![allow(unused_variables)]
pub mod box_ptr;
pub mod rc_ptr;
pub mod rc_weak;
pub mod refcell_ptr;

pub fn add(left: usize, right: usize) -> usize {
    left + right
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }
}
