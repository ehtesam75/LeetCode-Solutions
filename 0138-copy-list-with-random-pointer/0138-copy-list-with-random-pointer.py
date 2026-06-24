"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        mp = {}
        curr = head

        while curr:
            new_node = Node(curr.val)
            mp[curr] = new_node
            curr = curr.next

        curr = head
        if curr:
            copy_head = mp[curr]
        else:
            return curr #head null

        while curr:
            if curr.next:
                mp[curr].next = mp[curr.next]
            if curr.random:
                mp[curr].random = mp[curr.random]
            curr = curr.next
        
        return copy_head