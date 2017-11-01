"""
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
"""
def is_subtree(s, t):
    if not s:
        return False

    current = is_equal(s, t)

    if current:
        return True

    return is_subtree(s.left, t) or is_subtree(s.right, t)


def is_equal(a, b):
    if not a and not b:
        return True
    elif not a or not b:
        return False

    if a.val != b.val:
        return False

    left = is_equal(a.left, b.left)
    right = is_equal(a.right, b.right)

    return left and right
