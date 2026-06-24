# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head is None:
            return None

        curr = head
        cnt = 0

        while curr:
            cnt = cnt + 1
            curr = curr.next

        #if remove head
        if cnt == n:
            return head.next

        pos = cnt - n
        prev = None
        curr = head
        i = 0

        while i < pos:
            prev = curr
            curr = curr.next
            i += 1

        prev.next = curr.next

        return head
