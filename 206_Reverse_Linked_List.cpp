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
    ListNode* doReverse(ListNode* node) {
        ListNode* newHead = NULL;
        
        if (node == NULL) {
            return NULL;
        } else {
            newHead = doReverse(node->next);
            if (newHead == NULL) {
                return node;
            } else {
                node->next->next = node;
                return newHead;
            } 
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        
        if (head != NULL) {
            newHead = doReverse(head);
            head->next = NULL;
        }
        
        return newHead;
    }
};
