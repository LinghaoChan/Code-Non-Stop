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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        push_vec(root, v);
        return v;
    }
    void push_vec(TreeNode* root, vector<int>& v){
        if(root!=NULL){
            push_vec(root->left, v);
            v.push_back(root->val);
            push_vec(root->right, v);            
        }

    }
};