import Utility
import Data.List

multSum :: (Integral a) => a -> a -> a -> a
multSum x y limit = sum $ xMults ++ yMults
  where lim = limit - 1
        xMults = [a | a <- [1..lim], a `mod` x == 0]
        yMults = [a | a <- [1..lim], a `mod` y == 0, not (elem a xMults)]
