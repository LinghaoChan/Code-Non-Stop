#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;
struct ListNode {
	int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL&&l2==NULL){
            return NULL;
        }else if(l1==NULL&&l2!=NULL){
            return l2;
        }else if(l1!=NULL&&l2==NULL){
            return l1;
        }
        ListNode* p1 = l1;
		ListNode* p2 = l2;
        ListNode* newlist = new ListNode(l1->val);
        ListNode* lp = newlist;
        while(p1!=NULL&&p2!=NULL){
        	if(p1->val<=p2->val){
        		lp->next = new ListNode(p1->val);
        		p1 = p1->next;
        		lp = lp->next;
			} else{
        		lp->next = new ListNode(p2->val);
        		p2 = p2->next;
        		lp = lp->next;
			}
		}
		if(p1==NULL){
			lp->next = p2;
			return newlist->next;
		}if(p2==NULL){
			lp->next = p1;
			return newlist->next;
		}
		return newlist->next;
    }
};


int main(){
	
	
	return 0;
} 
