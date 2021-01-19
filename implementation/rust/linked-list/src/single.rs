use std::iter;
use std::mem;
use std::rc::Rc;

struct Node<T> {
    value: T,
    next: Option<Rc<Node<T>>>,
}

impl<T> Node<T> {
    pub fn new(value: T, next: Option<Rc<Node<T>>>) -> Node<T> {
        Node { value, next }
    }
}

pub struct List<T> {
    head: Option<Rc<Node<T>>>,
    tail: Option<Rc<Node<T>>>,
    size: usize,
}

impl<T> iter::IntoIterator for List<T> {
    type Item = T;
    type IntoIter = IntoIter<Self::Item>;

    fn into_iter(self) -> IntoIter<T> {
        IntoIter(self)
    }
}

impl<T> List<T> {
    pub fn new() -> List<T> {
        List {
            head: None,
            tail: None,
            size: 0,
        }
    }

    pub fn push_front(&mut self, value: T) {
        let node = match self.size {
            0 => Rc::new(Node::new(value, None)),
            1 => {
                let temp = Rc::new(Node::new(value, mem::replace(&mut self.head, None)));
                self.tail = match &temp.next {
                    Some(v) => Some(v.clone()),
                    None => None,
                };
                temp
            }
            _ => Rc::new(Node::new(value, mem::replace(&mut self.head, None))),
        };

        self.head = Some(node);
        self.size += 1;
    }

    pub fn pop_front(&mut self) -> Option<T> {
        if self.size == 0 {
            return None;
        }

        let node = match self.size {
            1 => mem::replace(&mut self.head, None),
            2 => mem::replace(&mut self.head, mem::replace(&mut self.tail, None)),
            _ => {
                let mut head = mem::replace(&mut self.head, None);
                self.head = mem::replace(&mut head, None);
                head
            }
        };

        self.size -= 1;

        return match node {
            Some(v) => match Rc::<Node<T>>::try_unwrap(v) {
                Ok(r) => Some(r.value),
                Err(_) => {
                    println!("Rc still held more than one strong reference");
                    panic!("Rc still held more than one strong reference");
                }
            },
            None => None,
        };
    }
}

pub struct IntoIter<T>(List<T>);

impl<T> Iterator for IntoIter<T> {
    type Item = T;

    fn next(&mut self) -> Option<Self::Item> {
        self.0.pop_front()
    }
}

#[cfg(test)]
mod tests {
    use super::List;

    #[test]
    fn single_front() {
        let mut list = List::<i64>::new();

        list.push_front(100);
        assert_eq!(list.size, 1);

        list.push_front(200);
        assert_eq!(list.size, 2);
    }
}
