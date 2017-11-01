import Utility
import Data.List

leastCommonMultiple1 :: [Integer] -> Integer
leastCommonMultiple1 factors = product primeFactorized
  where primeFactors = filter isPrimeNaive factors
        primeFactorized = map (`maxPower` (last factors)) primeFactors

leastCommonMultiple2 :: [Integer] -> Integer -> Integer
leastCommonMultiple2 factors initial
  | length factors == 0 = initial
  | otherwise = leastCommonMultiple2 factors' (lcm x initial)
  where x = head factors
        factors' = drop 1 factors
