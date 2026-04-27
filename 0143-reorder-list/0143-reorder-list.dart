/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  void reorderList(ListNode? head) {
    ListNode? slow = head, fast = head;
    while(slow != null && fast != null && fast.next != null){
        slow = slow.next;
        fast = fast.next!.next;
    }

    ListNode? start = slow!.next;
    slow.next = null;

    ListNode? prev = null, curr = start;
    while(curr != null){
        ListNode? next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
    }

    ListNode? h = head;
    while(h != slow && h != null && prev != null){
        ListNode? h_next = h.next;
        ListNode? prev_next = prev.next;
        h.next = prev;
        prev.next = h_next;
        prev = prev_next;
        h = h_next;
    }
  }
}