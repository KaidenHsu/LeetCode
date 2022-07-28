// 7/28/22
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
class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *before = dummy, *after = head, *curr = nullptr, *prev = nullptr ,*nxt = nullptr;

        while(true){
            ListNode* cursor = after;
            for(int i = 0; i < k; i++){
                if(cursor == nullptr) return dummy->next;
                cursor = cursor->next;
            }

            curr = after;
            prev = before;
            for(int i = 0; i < k; i++){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
        }
    }
};