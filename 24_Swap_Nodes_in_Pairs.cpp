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
        // not dummy head, and just simulation
        
        /*  不使用dummy head,而是直接操作
            ex : 1 -- 2 -- 3 -- 4 -- 5 -- 6
            一開始處理head交換部分,然後紀錄下一對的第一個node,也就是3
            tmp1 --> 用來記錄下一對的第一個node
            
            接著,因為1的next是3,但是當3和4交換後,也需要改變1的next成4
            所以需要另一個pointer來記錄1,當3和4交換後,就可以更新1的next
            tmp2 --> 用來記錄上一對的交換後的第二個node
            
        
         */
        ListNode* cur, *tmp1, *tmp2;
        
        cur = head;
        tmp2 = NULL;
        // 處理head部分
        if (cur != NULL && cur->next != NULL) {
            tmp1 = cur->next->next;
            head = cur->next;
            cur->next->next = cur;
            cur->next = tmp1;
            tmp2 = cur;
            cur = tmp1;
        }
        
        // 處理剩下node
        while (cur != NULL && cur->next != NULL) {
            cout << cur->val << " " << cur->next->val << endl;
            tmp1 = cur->next->next;
            cur->next->next = cur;
            tmp2->next = cur->next;
            cur->next = tmp1; 
            tmp2 = cur;
            cur = tmp1;
        }
        
        return head;
    }
};
