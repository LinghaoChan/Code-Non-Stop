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
    bool isBalanced(TreeNode* root) {
        if(root!=NULL){
            return (abs(height(root->left)-height(root->right))<=1)&&(isBalanced(root->left))&&(isBalanced(root->right));        
        }else{
            return true;
        }
    }
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }else if(root->left==NULL){
            return 1 + height(root->right);
        }else if(root->right==NULL){
            return 1 + height(root->left);
        }else if(root->left==NULL && root->right==NULL){
            return 1;
        }else{
            return 1 + (height(root->left)>height(root->right) ? height(root->left):height(root->right));
        }
    }
};