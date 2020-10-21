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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* p;
        inorder(original, cloned, target, p);
        return p;
    }
    void inorder(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* &p){
        if(original!=NULL){
            if(original==target){
                p = cloned;
                return;
            }else{
                inorder(original->left, cloned->left, target, p);
                inorder(original->right, cloned->right, target, p);
            }
        }
    }
};