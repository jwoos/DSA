#!/usr/bin/env python2
def answer(l, t):
    solution = None
    length = len(l)

    if length > 100 or t > 250:
        length = 0

    for i in range(length):
        current = 0

        if solution is not None or l[i] < 0 or l[i] > 100:
            break

        for j in range(i, length):
            current += l[j]

            if current == t:
                solution = [i, j]
            elif current > t:
                break

    return solution if solution is not None else [-1, -1]


print(answer([4, 3, 10, 2, 8], 12))
print(answer([4, 3, 5, 7, 8], 12))
print(answer([1, 2, 3, 4], 15))
