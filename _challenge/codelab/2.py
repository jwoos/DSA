"""
Given 2 non negative integers m and n, find gcd(m, n)

GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.
"""
def gcd(a, b):
    if a > b:
        if b == 0:
            return a
        return gcd(b, a % b)
    else:
        return gcd(a, b % a)

"""
Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
"""
def single_number(a):
    sol = 0
    for x in a:
        sol ^= x

    return sol

"""
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.
"""
def length_of_last_word(a):
    length = 0
    i = len(a) - 1

    while i >= 0:
        if a[i] != ' ':
            length += 1

        if length and a[i] == ' ':
            break
        i -= 1

    return length

"""
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
"""

def is_interleave_dp(a, b, c):
    if len(a) > len(c) or len(b) > len(c) or len(a) + len(b) > len(c):
        return False

    row = len(a) + 1
    col = len(b) + 1
    matrix = []

    for x in range(row):
        matrix.append([None] * col)

    matrix[0][0] = True

    for i in range(col - 1):
        if b[i] == c[i]:
            matrix[0][i + 1] = matrix[0][i]
        else:
            matrix[0][i + 1] = False

    for i in range(row - 1):
        if a[i] == c[i]:
            matrix[i + 1][0] = matrix[i][0]
        else:
            matrix[i + 1][0] = False

    for i in range(1, row):
        for j in range(1, col):
            if a[i - 1] == c[i + j - 1]:
                matrix[i][j] = matrix[i - 1][j]
            elif b[j - 1] == c[i + j - 1]:
                matrix[i][j] = matrix[i][j - 1]
            else:
                matrix[i][j] = False

    for x in matrix:
        print(x)

    return matrix[row - 1][col - 1]

def is_interleave_sort(a, b, c):
    ab = a + b
    return sorted(ab) == sorted(c)

if __name__ == '__main__':
    print(is_interleave_sort('LgR8D8k7t8KIprKDTQ7aoo7ed6mhKQwWlFxXpyjPkh', 'Q7wQk8rqjaH971SqSQJAMgqYyETo4KmlF4ybf', 'Q7wLgR8D8Qkk7t88KIrpqjarHKD971SqSQJTQ7aoAMgoq7eYd6yETmhoK4KmlQwWFlF4xybXfpyjPkh'))
