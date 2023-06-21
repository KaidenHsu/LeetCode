// 6/21/23

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *ahead = dummy, *behind = dummy;

        while (n--) ahead = ahead->next;

        while (ahead->next != nullptr) {
            ahead = ahead->next;
            behind = behind->next;
        }

        behind->next = behind->next->next;

        return dummy->next;
    }
};
