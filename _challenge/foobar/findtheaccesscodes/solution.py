#!/usr/bin/env python2

def answer(l):
    length = len(l)
    solution = 0

    while length >= 2:
        length -= 1
        left = len([x for x in l[:length] if l[length] % x == 0])
        right = len([x for x in l[length + 1:] if x % l[length] == 0])
        solution += left * right

    return solution

print answer(list(range(1, 10000)))
# print answer([1, 1])
