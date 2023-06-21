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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *curr = head, *tmp;

        head = head->next;

        while (curr && curr->next) {
            tmp = curr->next;

            curr->next = tmp->next;
            tmp->next = curr;

            curr = curr->next;
            if (curr && curr->next) {
                tmp->next->next = curr->next;
            }
        }

        return head;
    }
};
