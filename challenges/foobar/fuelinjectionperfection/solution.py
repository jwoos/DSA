#!/usr/bin/env python2

def answer(n):
    n = int(n)
    moves = 0

    while n > 1:
        if n & 0b1 == 0:
            n >>= 0b1
        elif n != 3 and n & 0b11 == 0b11:
            n += 1
        else:
            n -= 1

        moves += 1

    if n == 0:
        moves = 1

    return int(moves)

print answer('100000000000000000000000000000000000000000000000000000000')
print answer('65')
print answer('32')
print answer('18')
print answer('15')
print answer('4')
print answer('3')
print answer('1')
