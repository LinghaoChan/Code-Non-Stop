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
    vector<int> v;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        Preorder(root);
        return this->v;
    }
    void Preorder (TreeNode* root){
        if(root!=NULL){
            (this->v).push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }
};