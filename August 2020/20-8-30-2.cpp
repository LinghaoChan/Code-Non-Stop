#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <stack> 
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	if(root==NULL){
            return root;
    	}
    	TreeNode* tmp = root->left;
    	root->left = root->right;
    	root->right = tmp;
    	invertTree(root->left);
    	invertTree(root->right);
    	return root;
    }
};

int main(){
	cout<<"s";	
	return 0;
} 
