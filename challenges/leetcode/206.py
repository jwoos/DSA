"""
Reverse a singly linked list.
"""
from leetcode import ListNode


def recurse_list(node, prev=None):
    if node is None:
        return prev

    temp = node.next
    node.next = prev
    return recurse_list(temp, node)

def reverse_list(head):
    return recurse_list(head)
