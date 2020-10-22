/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }else if(!isDelete(root)){
            return nullptr;
        }else{
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
            return root;
        }
    }
    bool isDelete(TreeNode* root){
        if(root!=nullptr){
            return (root->val==1)||isDelete(root->left)||isDelete(root->right);        
        }else{
            return false;
        }
    }
};