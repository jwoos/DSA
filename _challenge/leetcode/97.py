"""
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
"""
def is_interleave(s1, s2, s3):
    s1_length = len(s1)
    s2_length = len(s2)
    s3_length = len(s3)

    if s1_length + s2_length != s3_length:
        return False

    row = s1_length + 1
    col = s2_length + 1

    # for memoization
    matrix = [[False for _ in range(col)] for _ in range(row)]

    # empty string is an interleave of empty string
    matrix[0][0] = True

    # what if we only had s1
    for i in range(1, row):
        i_decr = i - 1
        if s1[i_decr] == s3[i_decr]:
            matrix[i][0] = matrix[i_decr][0]

    # what if we only had s2
    for j in range(1, col):
        j_decr = j - 1
        if s2[j_decr] == s3[j_decr]:
            matrix[0][j] = matrix[0][j_decr]

    for i in range(1, row):
        for j in range(1, col):
            matrix[i][j] = (matrix[i-1][j] and s1[i-1] == s3[i+j-1]) or (matrix[i][j-1] and s2[j-1] == s3[i+j-1])

    return matrix[-1][-1]
