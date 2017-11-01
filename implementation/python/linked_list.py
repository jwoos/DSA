"""
Singly linked list
"""


class LinkedList:
    def __init__(self, head=None):
        self.head = head
        self.tail = head
        self.size = 1 if head else 0

    def _check_range(self, index):
        if index < 0 or index > max(self.size - 1, 0):
            raise Exception('Index out of range')

    def append(self, data):
        node = LinkedListNode(data=data)

        if not self.size:
            self.head = node
            self.tail = self.head
        else:
            self.tail.next = node
            self.tail = self.tail.next

        self.size += 1

    def pop(self, node=False):
        if self.size == 0:
            return

        if self.size == 1:
            current = self.head
            self.head = None
            self.tail = None
        else:
            previous = self.get(self.size - 2, node=True)
            current = previous.next
            self.tail = previous
            previous.next = None

        self.size -= 1
        return current if node else current.data

    def get(self, index, node=False):
        self._check_range(index)

        current = self.head

        while index > 0 and current.next is not None:
            index -= 1
            current = current.next

        if index != 0:
            raise Exception('Not Found')

        return current if node else current.data

    def find(self, data, fn=None):
        current = self.head

        for index in range(self.size):
            if not fn:
                if current.data == data:
                    return (index, current)
            else:
                if fn(current.data, data):
                    return (index, current)

            current = current.next

        return (-1, None)

    def insert(self, index, data):
        # head
        if index == 0:
            next = self.head
            self.head = LinkedListNode(data=data)
            self.tail = self.head
        #tail
        elif index == self.size:
            size = self.size
            self.append(data)
            self.size = size
        # other
        else:
            self._check_range(index)

            previous = self.get(index - 1, node=True)
            current = LinkedListNode(data=data)
            current.next = previous.next
            previous.next = current

        self.size += 1

    def delete(self, index):
        # head
        if index == 0:
            current = self.head
            self.head = self.head.next
            # remove from scope
            del current
        #tail
        elif index == self.size - 1:
            size = self.size
            self.pop(index)
            self.size = size
        # other
        else:
            self._check_range(index)

            previous = self.get(index, node=True)
            current = previous.next
            previous.next = current.next
            # remove from scope
            del current

        self.size -= 1

    def print(self, fn=None):
        current = self.head
        while current is not None:
            if fn:
                print(fn(current.data), end=' -> ')
            else:
                print(current.data, end=' -> ')
            current = current.next
        print()


class LinkedListNode:
    def __init__(self, data=None, next=None):
        self.next = next
        self.data = data
