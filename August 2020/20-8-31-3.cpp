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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root ==q)
            return root;
        else if((IsIntree(root->left, p))&&(IsIntree(root->left, q))) 
            return lowestCommonAncestor(root->left,p,q);
        else if((IsIntree(root->right, p))&&(IsIntree(root->right, q))) 
            return lowestCommonAncestor(root->right,p,q);
        else 
            return root;
    }
    bool IsIntree(TreeNode* root, TreeNode* target){
        
        if(root == target){
            return true;
        }
        
        else if(root->left != NULL && root->right != NULL){
            return (IsIntree(root->left,target) || IsIntree(root->right,target));
        }
        else if(root->left == NULL && root->right != NULL){
            return (IsIntree(root->right,target));
        }
        else if(root->left != NULL && root->right == NULL){
            return (IsIntree(root->left,target));
        }else{
            return false;
        }
    }
};