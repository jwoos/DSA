module List (
  List',
  head',
  last',
  tail',
  init'
) where

data List' a = Empty | Cons a (List' a) deriving (Show, Eq, Read)

head' :: List' a -> a
head' (Cons x xs) = x

last' :: List' a -> a
last' (Cons x xs) = last' xs

tail' :: List' a -> List' a
tail' (Cons x Empty) = Empty
tail' (Cons x xs) = xs

init' :: List' a -> List' a
init' (Cons x Empty) = Empty
init' (Cons x xs) = Cons x (init' xs)

length' :: (Integral n) => List' a -> n
length' Empty = 0
length' (Cons x Empty) = 1
length' (Cons x xs) = 1 + length' xs

uncons' :: List' a -> Maybe (a, List' a)
uncons' Empty = Nothing
uncons' (Cons x xs) = Just (x, xs)

null' :: List' a -> Bool
null' Empty = True
null' (Cons x xs) = False

map' :: (a -> b) -> List' a -> List' b
map' f Empty = Empty
map' f (Cons x Empty) = Cons (f x) Empty
map' f (Cons x xs) = Cons (f x) (map' f xs)

reverse' :: List' a -> List' a
reverse' Empty = Empty
reverse' (Cons x Empty) = Cons x Empty
