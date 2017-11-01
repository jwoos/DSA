import Utility
import Data.List

isNumPalindrome :: Integer -> Bool
isNumPalindrome n = str == reverse str
  where str = show n

compareLists :: ([Integer] -> Integer) -> [Integer] -> [Integer] -> Ordering
compareLists fnc a b
  | extractedA > extractedB = GT
  | extractedA < extractedB = LT
  | otherwise = EQ
  where extractedA = fnc a
        extractedB = fnc b

findTwoFactors :: Integer -> Integer -> [Integer]
findTwoFactors lower upper = maximumBy (compareLists last) palindromes
  where factors = [[x, y, x * y] | x <- [lower..upper], y <- [lower..upper]]
        palindromes = [lst | lst@(_:c) <- factors, isNumPalindrome $ last c]
