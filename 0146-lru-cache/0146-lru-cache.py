class Node:
    def __init__(self, data):
        self.val = data
        self.key = None
        self.next = None
        self.prev = None

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.mp = {}
        self.head = Node(0)
        self.tail = Node(0)

        self.head.next = self.tail
        self.tail.prev = self.head

    def remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
    
    def add_front(self, node):
        node.next = self.head.next
        node.prev = self.head

        self.head.next.prev = node
        self.head.next = node

    def get(self, key: int) -> int:
        if key not in self.mp:
            return -1
        
        node = self.mp[key]
        self.remove(node)
        self.add_front(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.mp:
            self.remove(self.mp[key])
            del self.mp[key]

        node = Node(value)
        node.key = key
        self.mp[key] = node
        self.add_front(node)

        if len(self.mp) > self.cap:
            lru = self.tail.prev
            self.remove(lru)
            del self.mp[lru.key]


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)