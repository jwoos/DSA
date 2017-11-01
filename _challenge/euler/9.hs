isPythagoreanTriplet :: Integer -> Integer -> Integer -> Bool
isPythagoreanTriplet a b c
  | a^2 + b^2 == c^2 = True
  | otherwise = False

pythagoreanTriplet :: Integer -> (Integer, Integer, Integer)
pythagoreanTriplet upper = head [(a, b, c) | a <- [1..(upper `quot` 3)], b <- [1..(upper `quot` 2)], let c = upper - (a + b), isPythagoreanTriplet a b c]
