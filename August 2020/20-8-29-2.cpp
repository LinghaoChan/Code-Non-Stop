#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <stack> 
using namespace std;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* pA = headA, *pB = headB;
        if(pA == NULL || pB == NULL)return NULL;
		while(1){
			if(pA == pB){
				return pA;
			}
            if(pB->next ==NULL&&pA->next==NULL)return NULL;
			if(pA->next == NULL){
				pA = headB;
				pB  = pB->next;
			}else if(pB->next == NULL){
				pB = headA;
				pA = pA->next;
			}else{
				pA = pA->next;
				pB = pB->next;
			}
            if(pA == pB){
				return pA;
			}
		}
    }
};

int main(){
	
	
	return 0;
} 
