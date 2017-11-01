import Utility
import Data.List

nPrimes :: (Integral a) => Int -> [a]
nPrimes n = [2] ++ take (n - 1) [x | x <- [3,5..], isPrimeNaive x]

nthPrime :: (Integral a) => Int -> a
nthPrime n = last $ take (n + 1) [x | x <- [3,5..], isPrimeNaive x]
