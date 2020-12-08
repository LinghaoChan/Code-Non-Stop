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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* l = new ListNode(val-1);
        ListNode* pre = l;
        l->next = head;
        ListNode* p = head;
        while(p!=NULL){
            if(p->val==val){
                l->next = p->next;
                p=p->next;
            }else{
                l=l->next;
                p=p->next;
            }

        }
        return pre->next;
    }
};