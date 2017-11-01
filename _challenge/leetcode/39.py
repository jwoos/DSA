"""
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
    bool is_match(const char *s, const char *p)
"""


class ASTNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def is_match(s, p):
    # parse regex into simple AST
    root = ASTNode('')
    current = root

    for i in range(len(p)):
        curr = ASTNode(p[i])

        if p[i] == '*':
            current.left = curr
        else:
            current.right = curr
            current = current.right

    current = root
    s_index = 0

    while current is not None and s_index < len(s):
        if current.val == '.' or current.val == s[s_index]:
            s_index += 1

        if current.left is not None and s_index < len(s):
            if s[s_index] != current.val:
                current = current.right
            elif current.right is not None and current.right.val == s[s_index]:
                current = current.right
            elif current.val == s[s_index] or current.val == '.':
                continue
        else:
            current = current.right


    print(s_index)
    print(s_index == len(s), not current)
    return s_index == len(s) and not current

print(is_match('aaa', 'a*a'))
