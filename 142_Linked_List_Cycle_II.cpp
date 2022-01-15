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
    ListNode* moveForward(ListNode* node, int nums) {
        while (node != NULL && (nums--) > 0) {
            node = node->next;
        }
        
        return node;
    }
    
    ListNode *detectCycle(ListNode *head) {
        // two pointers solution
        ListNode* fast = head;
        ListNode* slow = head;
        
        // Check if exists a cycle
        while (fast != NULL) {
            fast = moveForward(fast, 2); // move forward 2 nodes
            slow = moveForward(slow, 1);  // move forward 1 node
            if (fast == slow) { // fast meets slow in the cycle
                break;
            }
        }
        
        if (fast != NULL) { // exists a cycle
            slow = head;
            while (fast != slow) { // find the entry node of the cycle
                fast = moveForward(fast, 1);
                slow = moveForward(slow, 1);
            }
        }
        
        return fast;
    }
};
