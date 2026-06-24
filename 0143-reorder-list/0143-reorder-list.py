# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        #lets go the middle
        slow = head
        fast = head

        while slow.next and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        #reverse from middle
        prev = None
        curr = slow.next
        slow.next = None

        while curr:
            nxt = curr.next
            curr.next = prev

            prev = curr
            curr = nxt

        #merging both parts
        first = head
        last = prev

        while last:
            first_nxt = first.next
            last_nxt = last.next

            first.next = last
            last.next = first_nxt

            first = first_nxt
            last = last_nxt


        