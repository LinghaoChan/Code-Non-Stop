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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return true;
        }
        ListNode* slow = head, * fast = head;
        ListNode* p1 = NULL, * p2 = NULL;
        while(fast && fast->next){
            p1 = slow;
            slow = slow->next;
            fast = fast->next->next;
            p1->next = p2;
            p2 = p1;
        }
        if(fast == NULL){
            fast = p2;
        }else{
            fast = p2;
            slow = slow->next;
        }
        while(fast!=NULL && slow!=NULL){
            // cout<<fast->val<<"  "<<slow->val;
            if(fast->val != slow->val){
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};