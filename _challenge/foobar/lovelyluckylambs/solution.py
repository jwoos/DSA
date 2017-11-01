#!/usr/bin/env python2

def answer(total_lambs):
    if total_lambs < 10 or total_lambs > pow(10, 9):
        return 0

    # fib sequence
    stingy_count = 1
    stingy_total = 1
    stingy_prev = 0
    stingy_current = 1
    stingy_continue = True

    # powers of 2 sequence
    generous_count = 1
    generous_total = 1
    generous_prev = 0
    generous_current = 1
    generous_continue = True

    while True:
        if stingy_continue:
            stingy_current, stingy_prev = stingy_current + stingy_prev, stingy_current
            stingy_total += stingy_current

            if stingy_total <= total_lambs:
                stingy_count += 1
            else:
                stingy_continue = False

        if generous_continue:
            temp = generous_total + generous_current * 2

            if temp <= total_lambs:
                generous_count += 1
                generous_current, generous_prev = generous_current * 2, generous_current
                generous_total += generous_current
            else:
                generous_continue = False

        if not generous_continue:
            two_prev = generous_current + generous_prev
            diff = total_lambs - generous_total
            generous_count += 1
            generous_total += two_prev
            generous_current, generous_prev = generous_current + generous_prev, generous_current

        if not stingy_continue and not generous_continue:
            break

    return abs(stingy_count - generous_count)

print(answer(0))
print(answer(13))
