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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* pre = head;
        ListNode* aft = head->next;
        while(aft!=NULL&&pre->next!=NULL){
            if(aft->val==pre->val){
                if(aft->next==NULL){
                    pre->next = NULL;
                    //cout<<'1';
                }else{
                    aft = aft->next;
                    pre->next = aft;
                    //cout<<'2';
                }
            }else{
                pre = pre->next;
                aft = aft->next;
            }
        }
        return head;
    }
};