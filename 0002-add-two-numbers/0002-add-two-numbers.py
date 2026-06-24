# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # #list1 reverse
        # prev1 = None
        # curr1 = l1

        # while curr1:
        #     nxt = curr1.next
        #     curr1.next = prev1

        #     prev1 = curr1
        #     curr1 = nxt

        # #list2 reverse
        # prev2 = None
        # curr2 = l2

        # while curr2:
        #     nxt = curr2.next
        #     curr2.next = prev2

        #     prev2 = curr2
        #     curr2 = nxt

        
        temp1 = l1
        temp2 = l2
        dummy = ListNode(-1)
        mov = dummy

        carry = 0
        while temp1 and temp2:
            sum = temp1.val + temp2.val + carry
            mov.next = ListNode(sum % 10)
            if temp1.val + temp2.val + carry > 9:
                carry = 1
            else:
                carry = 0

            temp1 = temp1.next
            temp2 = temp2.next
            mov = mov.next
        
        while temp1:
            sum = temp1.val + carry
            mov.next = ListNode(sum % 10)
            if temp1.val + carry > 9:
                carry = 1
            else:
                carry = 0

            temp1 = temp1.next
            mov = mov.next

        while temp2:
            sum = temp2.val + carry
            mov.next = ListNode(sum % 10)
            if temp2.val + carry > 9:
                carry = 1
            else:
                carry = 0

            temp2 = temp2.next
            mov = mov.next
        
        if carry:
            mov.next = ListNode(carry)

        return dummy.next