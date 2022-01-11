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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Time complexity : O(m*n)
        ListNode* ptrA = headA;
        ListNode* ptrB;
        
        while (ptrA != NULL) {
            ptrB = headB;
            while (ptrB != NULL) {
                if (ptrA == ptrB) {
                    return ptrA;
                }
                
                ptrB = ptrB->next;
            }
            
            ptrA = ptrA->next;
        }
        
        return NULL;
    }
};
