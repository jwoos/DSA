"""
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
"""
def add_binary(a, b):
    fill = max(len(a), len(b))
    a = a.zfill(fill)
    b = b.zfill(fill)

    solution = []
    carry = 0
    for i in range(fill - 1, -1, -1):
        int_a = int(a[i])
        int_b = int(b[i])
        curr = 0

        if int_a & int_b:
            curr = carry
            carry = 1
        elif int_a ^ int_b:
            if carry:
                curr = 0
                carry = 1
            else:
                curr = 1
        else:
            curr = carry
            if carry:
                carry = 0

        solution.append(str(curr))

    if carry:
        solution.append(str(carry))

    return ''.join(reversed(solution))
