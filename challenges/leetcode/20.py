"""
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
"""

def is_valid(s):
    MAPPING = {
        '[': ']',
        '(': ')',
        '{': '}'
    }
    REVERSE_MAPPING = {v: k for k, v in MAPPING.items()}

    valid = True
    stack = []
    for x in s:
        if x in MAPPING:
            stack.append(x)
        else:
            if not stack or stack[-1] != REVERSE_MAPPING[x]:
                valid = False
                break

            stack.pop()

    return valid and not stack
