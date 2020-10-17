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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == NULL)    return NULL;
        vector<TreeNode*> vec;
        inorder(root, vec);
        if(p == vec[vec.size()-1])  return NULL;
        for(int i = 0; i < vec.size()-1; i++){
            if(vec[i] == p) return vec[i+1];
        }
        return NULL;
    }
    void inorder(TreeNode* root, vector<TreeNode*>& vec){
        if(root!=NULL){
            inorder(root->left, vec);
            vec.emplace_back(root);
            inorder(root->right, vec);
        }
    }
};