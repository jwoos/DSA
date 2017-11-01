module MathHelper (
  isPrimeNaive,
  greatestPowerOf2,
  find2dr
                  ) where

isPrimeNaive :: Integer -> Bool
isPrimeNaive n
  | length factors == 1 = True
  | otherwise = False
    where factors = [f | f <- [1..(floor $ sqrt $ fromIntegral n)], n `mod` f == 0]


-- outer loop checks a^d and handles base cases
isPrimeMillerRabin :: (Integral a) => a -> a -> Bool
isPrimeMillerRabin n a
  | n < 0 = error $ "n out of range"
  | n == 0 || n == 1 = False
  | n == 2 || n == 3 = True
  | x == 1 || x == n' = True
  | otherwise = innerMillerRabin (n, x)
  where n' = n - 1
        (d, r) = find2dr n'
        x = (a ^ d) `mod` n

-- inner loop of miller rabin which checks a^(2^r * d)
innerMillerRabin :: (Integral a) => (a, a) -> Bool
innerMillerRabin (n, x)
  | x' == 1 = False
  | x' == (n - 1) = True
  | otherwise = innerMillerRabin (n, x')
  where x' = (x ^ 2) `mod` n

-- computes 2^r * d and returns (d, r)
find2dr :: (Integral a) => a -> (a, a)
find2dr n = (fst $ n `quotRem` (2^power), power)
  where power = greatestPowerOf2 n

-- find greated power of 2 possible for positive integer
greatestPowerOf2 :: (Integral a) => a -> a
greatestPowerOf2 n
  | n <= 0 = error "n cannot be less than or equal to 0"
  | n == 1 = 0
  | r == 0 = 1 + (greatestPowerOf2 q)
  | otherwise = 0
  where (q, r) = quotRem n 2
