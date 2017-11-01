"""
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
"""

from queue import PriorityQueue

def merge_k_lists(lists):
    pq = PriorityQueue()
    for l in lists:
        if l:
            pq.put((l.val, l), block=False)

    root = ListNode(None)
    current = root
    while not pq.empty():
        _, node = pq.get(block=False)
        current.next = node
        current = node
        if node.next is not None:
            pq.put((node.next.val, node.next), block=False)

    return root.next
