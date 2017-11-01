"""
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
"""

from leetcode import ListNode


def delete_duplicates(head):
    current = head
    next = None

    while current is not None:
        next = current.next
        while next is not None and next.val == current.val:
            current.next = next.next
            next = current.next

        current = current.next

    return head
