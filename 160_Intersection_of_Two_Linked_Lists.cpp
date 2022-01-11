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
        int lenA = 0, lenB = 0, diff = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        
        while (curA != NULL) {
            curA = curA->next;
            lenA++;
        }
        
        while (curB != NULL) {
            curB = curB->next;
            lenB++;
        }
        
        curA = headA;
        curB = headB;
        
        diff = (lenA - lenB >= 0) ? (lenA - lenB) : (lenB - lenA);
        
        if (lenA > lenB) {
            // 讓curA之後的長度和curB對齊
            while (diff > 0) {
                curA = curA->next;
                diff--;
            }
        } else if (lenA < lenB) {
            // 讓curB之後的長度和curA對齊
            while (diff > 0) {
                curB = curB->next;
                diff--;
            }
        }
        
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            
            curA = curA->next;
            curB = curB->next;
        }
        
        return NULL;
    }
};
