/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast;
        if(head != nullptr) fast = head->next;

        while(slow != nullptr and fast != nullptr and fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return 1;
        }
        return 0;
    }
};