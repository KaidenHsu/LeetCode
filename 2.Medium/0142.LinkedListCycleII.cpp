// 7/21/22
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next) return NULL;
        
        ListNode *turtle = head, *hare = head;
        
        while (hare->next && hare->next->next) {
            hare = hare->next->next;
            turtle = turtle->next;
            if (hare == turtle) break;
        }
        
        if (hare != turtle) return NULL;
        
        turtle = head;
        while (turtle != hare) {
            hare = hare->next;
            turtle = turtle->next;
        }
        
        return turtle;
    }
};