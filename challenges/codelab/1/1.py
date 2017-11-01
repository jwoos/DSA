"""
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.
"""
def detect_cycke(self, a):
    elem = {}
    current = a
    while current is not None:
        if elem.get(current.val) is not None:
            return elem.get(current.val)
        else:
            elem[current.val] = current

        current = current.next
    return None

"""
Given a sorted linked list, delete all duplicates such that each element appear only once.
"""
def delete_deplicates(self, a):
    prev = a
    current = a.next
    while current is not None:
	if current.val == prev.val:
	    prev.next = current.next
	    current = prev.next
	else:
	    prev = prev.next
	    current = current.next

    return a<Paste>
