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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* q = head;
        ListNode* x = q;
        vector<int> num;
        while(p!=nullptr){
            num.push_back(p->val);
            p = p->next;
        }
        int i;
        for(i = num.size() - 1; i>=0; i--){
            q->val = num[i];
            if(i!=0){
                ListNode* temp = new ListNode();
                q->next = temp;
                q = q->next;                
            }

        }
        if(q!=nullptr)
        q->next = nullptr;
        return x;
    }
};