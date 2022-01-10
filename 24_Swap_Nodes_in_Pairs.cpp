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
        // dummy head solution
        ListNode* dummyHead = new ListNode();
        ListNode* cur, *tmp1, *tmp2;
        
        dummyHead->next = head;
        cur = dummyHead;
        while (cur->next != NULL && cur->next->next != NULL) {
            tmp1 = cur->next;
            tmp2 = cur->next->next->next;
            
            cur->next = tmp1->next;
            cur->next->next = tmp1;
            tmp1->next = tmp2;
            cur = tmp1;
        }
        
        head = dummyHead->next;
        delete dummyHead;
        
        return head; 
    }
};
