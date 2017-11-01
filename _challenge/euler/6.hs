import Utility
import Data.List

sumSquareDifference :: Integer -> Integer -> Integer
sumSquareDifference lower upper = sumSquare - squareSum
  where range = [lower..upper]
        sumSquare = (sum range)^2
        squareSum = sum $ map (^2) range

