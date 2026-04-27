/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  ListNode? mergeTwoLists(ListNode? list1, ListNode? list2) {
    ListNode dummy = ListNode(0);
    ListNode curr = dummy;
    ListNode? l1 = list1, l2 = list2;

    while(l1 != null && l2 != null){
        if(l1.val <= l2.val){
            curr.next = l1;
            l1 = l1.next;
        }
        else{
            curr.next = l2;
            l2 = l2.next;
        }
        curr = curr.next!;
    }

    curr.next = l1 ?? l2;
    return dummy.next;
  }
}