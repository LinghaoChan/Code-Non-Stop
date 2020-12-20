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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2;
        ListNode* ret = new ListNode();
        ListNode* tmp = NULL;
        ListNode* x = ret;
        int last = 0;
        while(p1!=NULL && p2!=NULL){
            int t = p1->val + p2->val + last;
            last = t / 10;
            tmp = new ListNode(t % 10);
            x->next = tmp;
            x = x->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1!=NULL){
            x->next = p1;
            while(p1!=NULL){
                if(p1->val + last < 10){
                    p1->val += last;
                    last = 0;
                    break;
                }else{
                    p1->val += last;
                    last = p1->val / 10;
                    p1->val %= 10;
                }
                p1 = p1->next;
            }
        }else if(p2!=NULL){
            x->next = p2;
            while(p2!=NULL){
                if(p2->val + last < 10){
                    p2->val += last;
                    last = 0;
                    break;
                }else{
                    p2->val += last;
                    last = p2->val / 10;
                    p2->val %= 10;
                }   
                p2 = p2->next; 
            }        
        }
        if(last!=0){
            while(x->next!=NULL){
                x = x->next;
            }
            x->next = new ListNode(last);
        }
        return ret->next;

    }
};