import Utility
import Data.List

primeFactors :: Integer -> [Integer]
primeFactors n = [x | x <- [1, 3..(floor $ sqrt $ fromIntegral n)], isPrimeNaive x, n `mod` x == 0]
