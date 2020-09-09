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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }else{
            root->val = 0;
            return Sumval(root);
        }

    }
    int Sumval(TreeNode* root){
        if(root==NULL){
            return 0;
        }else if(root->left!=NULL && root->right==NULL){
            if(root->left->left==NULL && root->left->right==NULL)
                return root->left->val + Sumval(root->left);
            else
                return Sumval(root->left);
        }else if(root->left==NULL && root->right!=NULL){        
                return Sumval(root->right);
        }else if(root->left==NULL && root->right==NULL){
            return 0;
        }else{
            if(root->left->left==NULL && root->left->right==NULL)
                return root->left->val + Sumval(root->left) + Sumval(root->right);
            else
                return Sumval(root->left) + Sumval(root->right);
        }
    }
};