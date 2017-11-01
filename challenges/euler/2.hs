import Utility
import Data.List

sumFibLim :: (Integral a) => (a -> Bool) -> a -> (a, a) -> a
sumFibLim f lim (x, y) = sum $ takeWhile (<= lim) seq
  where seq = [x | x <- fibonacci, f x]
        fibonacci = x : y : (zipWith (+) fibonacci (tail fibonacci))
