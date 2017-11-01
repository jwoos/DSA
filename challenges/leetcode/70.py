"""
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
"""
def climb_stairs(n):
    # basically recurrence
    # r_n = r_{n-1} + r_n{n-2}
    # also fib!
    a = 1
    b = 1
    for x in range(n - 1):
        a, b = b, a + b

    return b
