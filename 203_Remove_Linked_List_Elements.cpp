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
    ListNode* removeElements(ListNode* head, int val) {
        /* dummy head solution
           dummy head可以統一用"檢查下一個node是不是要delete"
         */
        
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* pCurrent = dummyHead;
        ListNode* tmp = NULL;
        
        /* 不需要用另一個pointer指向前一個node */
        while (pCurrent->next != NULL) {
            if (pCurrent->next->val == val) {
                tmp = pCurrent->next;
                pCurrent->next = pCurrent->next->next;
                
                delete tmp;
            } else {
                pCurrent = pCurrent->next;
            }
        }
        
        head = dummyHead->next;
        delete dummyHead;
        
        return head;
    }
};
