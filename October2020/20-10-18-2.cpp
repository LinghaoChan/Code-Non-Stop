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
        int len = 1;
        ListNode* list = head;
        while(list->next != nullptr){
            len++;
            list = list->next;
        }
        int index = len - n + 1;
        ListNode* p = new ListNode(0, head);
        ListNode* pp = p;
        ListNode* q = head;
        int i = 1;
        while(q != nullptr){
            if(i==index){
                p->next = q->next;
                // delete q;
                return pp->next;
            }
            p = p->next;
            q = q->next;
            i++;
        }
        return pp->next;     
    }
};