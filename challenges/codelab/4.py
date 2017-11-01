from decimal import Decimal
import math
import sys


"""
N light bulbs are connected by a wire. Each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb. Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs. You can press the same switch multiple times.
"""
def bulbs(lights):
    count = 0
    for light in lights:
        if count & 1 != 0:
            if light == 1:
                light = 0
            else:
                light = 1

        if light == 0:
            count += 1

    return count

"""
You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. You have to accommodate the horses into the stables in such a way that the following conditions are satisfied:

You fill the horses into the stables preserving the relative order of horses. For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. You have to preserve the ordering of the horses.
No stable should be empty and no horse should be left unaccommodated.
Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum among all possible accommodation arrangements
"""
def arrange(horses, k):
    n = len(horses)
    if n < k:
        return -1
    elif k == 0:
        return 0

    matrix = [[None for _ in range(k)] for _ in range(n)]

    white = 0
    black = 0
    for i in range(n):
        if horses[i] == 'W':
            white += 1
        else:
            black += 1
        matrix[i][0] = black * white

    for j in range(1, k):
        for i in range(n):
            black = 0
            white = 0

            matrix[i][j] = sys.maxsize

            for x in range(i, -1, -1):
                if horses[x] == 'W':
                    white += 1
                else:
                    black += 1

                if x - 1 >= 0:
                    matrix[i][j] = min(matrix[i][j], black * white + matrix[x - 1][j - 1])
                else:
                    matrix[i][j] = min(matrix[i][j], black * white)

    return matrix[-1][-1]

"""
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach's conjecture
"""
def is_prime(n):
    if n < 2:
        return False

    for x in range(2, int(n ** 0.5) + 1):
        if n % x == 0 and x != n:
            return False

    return True

def primesum(a):
    for x in range(1, a):
        if is_prime(x) and is_prime(a - x):
            return (x, a - x)


"""
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.
"""
def is_power(n):
    if n == 1:
        return True

    for x in range(2, int(n ** 0.5) + 1):
        if n % x == 0:
            res = Decimal(n).log10() / Decimal(x).log10()
            if math.floor(res) == res:
                return True

    return False
