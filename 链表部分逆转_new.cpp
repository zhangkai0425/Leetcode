/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode *reverse(ListNode *start){
        ListNode *p = nullptr;
        while(start){
            ListNode *temp = start->next;
            start->next = p;
            p = start;
            start = temp;
        }
        return p;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        ListNode *p = head;
        ListNode *new_head = head;
        int kk = k;
        ListNode *ne = nullptr;
        ListNode *tail = nullptr;
        while(p){
            if(kk==1){
                ne = p->next;
                p->next = nullptr;
                ListNode *temp = reverse(head);
                if(new_head==head)
                    new_head = temp;
                if(tail) 
                    tail->next = p;
                tail = head;
              
                head = ne;
                p = ne;
                kk = k;
                continue;
            }
            kk--;
            p = p->next;
        }
        if(tail)
            tail->next = head;
        return new_head;
    }
};
