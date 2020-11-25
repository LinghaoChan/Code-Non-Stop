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
    vector<TreeNode*> tree;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        fun(root);
        int a = tree.size();
        for(int i = 0; i < a-1; i++){

            tree[i]->right = tree[i+1];
            tree[i]->left = nullptr;

        }
        tree[a-1]->left = nullptr;
        tree[a-1]->right = nullptr;
        TreeNode* pp = tree[0];
        return pp;
    }
    void fun(TreeNode* root){
        if(root!=nullptr){
            fun(root->left);
            tree.push_back(root);
            fun(root->right);
        }
    }
};