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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            return new TreeNode(val);
        }
        TreeNode* p = root;
        while(p!=nullptr){
            if(val < p->val){
                if(p->left==nullptr){
                    TreeNode* t = new TreeNode(val);
                    p->left = t;
                    break;
                }else{
                    p = p->left;
                }
            }else{
                if(p->right==nullptr){
                    TreeNode* t = new TreeNode(val);
                    p->right = t;
                    break;
                }else{
                    p = p->right;
                }            
            }
        }
        return root;
    }
};