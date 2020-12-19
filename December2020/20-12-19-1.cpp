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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* tmp = head;
        int length = 1;
        while(tmp->next != nullptr){
            tmp = tmp->next;
            length ++;
        }
        tmp->next = head; 
        ListNode* c_list = head;  
        ListNode* prev = tmp; 
        for(int i=1; i<=length - k%length; i++){
            c_list = c_list->next;
            prev = prev->next;
        }
        prev->next = nullptr;
        return c_list;
    }
};