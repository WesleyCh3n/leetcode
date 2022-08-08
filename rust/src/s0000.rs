pub struct Solution {}

impl Solution {
    pub fn foo() -> bool{
        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        assert_eq!(Solution::foo(), true);
    }
}
