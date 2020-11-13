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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* newnode = head->next;
        ListNode* p = head;
        ListNode* q = head->next;
        while(q!=nullptr && q->next!=nullptr){
            // cout<<"s";
            p->next = p->next->next;
            q->next= q->next->next;
            p = p->next;
            q = q->next;
        }
        p->next = newnode;
        return head;
    }
};