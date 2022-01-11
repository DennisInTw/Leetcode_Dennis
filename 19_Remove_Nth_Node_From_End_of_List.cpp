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
        // dummy head + two pointers
        ListNode* dummyHead = new ListNode();
        ListNode* fast, *slow, *tmp;
        
        dummyHead->next = head;
        fast = slow = dummyHead;
        
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        tmp = slow->next;
        slow->next = tmp->next;
        
        delete tmp;
        
        head = dummyHead->next;
        
        return head;
    }
};
