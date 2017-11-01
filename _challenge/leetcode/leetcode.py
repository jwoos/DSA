class Interval(object):
    def __init__(self, start=0, end=0):
        self.start = start
        self.end = end

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def show(self):
        current = self
        while current is not None:
            print current.val
            current = current.next
