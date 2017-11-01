#!/usr/bin/env python2

def answer(x):
    sum = 0
    int_str = str(x)

    for a_number in list(int_str):
        sum += int(a_number)
    if sum < 10:
        return sum
    else:
        return answer(sum)
