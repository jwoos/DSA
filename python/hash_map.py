"""
Hashmap that does closed addressing (chaining) to resolve hash collisions.
"""
from linked_list import LinkedList


class HashMapNode:
    def __init__(self, key, data):
        self.key = key
        self.data = data


class HashMap:
    def __init__(self, size):
        """
        Construct a hash map and initialize any internals.

        @type size: int
        @param size: the size of the hashmap
        """
        self.max_size = size
        self.size = 0
        self._store = [None] * self.max_size

    def _hash(self, key):
        return hash(key) % self.max_size

    def set(self, key, data):
        """
        Set a value in the hash map

        @type key: str
        @param key: the key to use in finding the location
            of the value

        @type data: any
        @param data: the value to set

        @rtype: bool
        @returns: True if successful, otherwise False
        """
        if self.size == self.max_size:
            return False

        index = self._hash(key)
        should_add = True
        # found a list already
        if self._store[index]:
            chain = self._store[index]
            _, node = chain.find(key, fn=lambda a, b: a.key == b)

            if index != -1 and node is not None:
                node.data.data = data
                should_add = False
        # first at the index
        else:
            chain = LinkedList()
            self._store[index] = chain

        if should_add:
            chain.append(HashMapNode(key, data))
            self.size += 1


        return True

    def get(self, key):
        """
        Get the value stored under the key

        @type key: str
        @param key: the key to use in finding the location
            of the value

        @rtype: any
        @returns: the value stored at the key
        """
        index = self._hash(key)
        chain = self._store[index]
        data = None

        if chain:
            _, list_node = chain.find(key, fn=lambda a, b: a.key == b)

            if list_node:
                data = list_node.data.data

        return data

    def delete(self, key):
        """
        Delete the value stored at the key

        @type key: str
        @param key: the key to use in finding the location
            of the value

        @rtype: any
        @returns: The value deleted if successful, otherwise
            None
        """
        index = self._hash(key)
        chain = self._store[index]
        data = None

        if chain:
            chain_index, list_node = chain.find(key, fn=lambda a, b: a.key == b)

            if list_node is not None:
                chain.delete(chain_index)
                self.size -= 1
                data = list_node.data.data

        return data

    def load(self):
        """
        Get the load factor (items in hash map)/(size of hash map)

        @rtype: float
        @returns: the load factor
        """
        return self.size / self.max_size

    def print(self):
        for x in self._store:
            if x:
                x.print(fn=lambda x: (x.key, x.data))
            else:
                print('None')
