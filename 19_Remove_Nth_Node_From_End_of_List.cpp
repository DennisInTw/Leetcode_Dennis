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
        // 利用array將所有node的address儲存,然後再依照index來找到需要刪除的node
        
        ListNode* dummyHead = new ListNode();
        ListNode* storePtr[31];
        ListNode* cur;
        int i;
        
        memset(storePtr, NULL, sizeof(ListNode*) * 31);
        
        dummyHead->next = head;
        cur = dummyHead;
        for (i = 0; cur != NULL; i++) {
            storePtr[i] = cur;
            cur = cur->next;
        }
        
        // i-1 is the number of nodes in the list
        storePtr[i-1-n]->next = storePtr[i-1-n+2];
        delete storePtr[i-1-n+1];
        
        head = dummyHead->next;
        
        return head;
    }
};
