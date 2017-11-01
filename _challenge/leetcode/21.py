"""
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
"""
def merge_two_lists(l1, l2):
    l1_current = l1
    l2_current = l2

    sorts = ListNode(None)
    actual = sorts
    while l1_current is not None and l2_current is not None:
        if l1_current.val < l2_current.val:
            actual.next = l1_current
            l1_current = l1_current.next
            actual = actual.next
        else:
            actual.next = l2_current
            l2_current = l2_current.next
            actual = actual.next

    if l1_current is not None:
        actual.next = l1_current
    elif l2_current is not None:
        actual.next = l2_current

    return sorts.next
