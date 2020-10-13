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
        ListNode* node = new ListNode(0, nullptr);
        node->next = head;
        ListNode* p  = node;
        while(p->next!=nullptr&&p->next->next!=nullptr){
            ListNode* q = p->next->next;
            p->next->next = q->next;
            q->next = p->next;
            p->next = q;
            p = p->next->next;
        }
        return node->next;
    }
};