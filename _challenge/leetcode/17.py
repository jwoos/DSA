"""
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
"""

MAPPING = [
    None,
    None,
    'abc',
    'def',
    'ghi',
    'jkl',
    'mno',
    'pqrs',
    'tuv',
    'wxyz'
]

def letter_combinations(digits):
    """
    :type digits: str
    :rtype: List[str]
    """
    if not digits:
        return []

    solutions = list(MAPPING[int(digits[0])])

    for i, x in enumerate(digits):
        if i == 0:
            continue

        current = MAPPING[int(x)]
        previous_length = len(solutions)
        current_length = len(current)
        mulitplier = 0
        solutions = solutions * current_length

        for c in current:
            start = mulitplier * previous_length
            mulitplier += 1
            end = mulitplier * previous_length
            for i in range(start, end):
                solutions[i] += c

    return solutions

print(letter_combinations('234'))
