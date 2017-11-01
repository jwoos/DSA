#!/usr/bin/env python2

"""
n XOR 0 = n
n XOR n = 0
"""

def xor(a, b):
    diff = b - a

    if diff == 0:
        return 0
    elif diff == 0:
        return a
    elif diff < 5:
        return reduce(lambda c, d: c ^ d, range(a, b))

    return xor(a, a / 4 * 4 + 4) ^ xor(b / 4 * 4, b)

def answer(start, length):
    line = [(
        start + (length - i) * length,
        start + (length - i) * length + i
    ) for i in range(length, 0, -1)]

    return reduce(lambda a, b: a ^ b, [xor(start, end) for start, end in line])
