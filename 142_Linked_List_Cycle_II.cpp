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
    ListNode *detectCycle(ListNode *head) {
        /* 將經過的node的val改成stopVal,下次遇到node的val為stopVal就表示為cycle的點
           最後再將儲存起來的val還原
           Space complexity : O(node個數)
        */
        int nodeVal[10000];
        int i = 0;
        ListNode* ans = NULL;
        ListNode* cur = head, *tmp = head;
        const int stopVal = -100001;
        
        while (cur != NULL) {
            if (cur->val == stopVal) {
                ans = cur;
                break;
            }
            nodeVal[i++] = cur->val; // 將node的val儲存起來
            cur->val = stopVal;
            cur = cur->next;
        }
        
        i = 0;
        // recover node value
        while (tmp != NULL) {
            if (tmp->val == stopVal) {
                tmp->val = nodeVal[i++];
                tmp = tmp->next;
            } else {
                break;
            }
        }
        
        return ans;
    }
};
