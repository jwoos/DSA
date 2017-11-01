"""
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.
"""
def hamming_distance(a, b):
    xor = a ^ b
    res = 0

    current = xor
    while current:
        rem = current % 2
        if rem:
            res += 1

        current = current // 2

    return res
