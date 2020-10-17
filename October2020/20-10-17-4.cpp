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
    TreeNode* convertBiNode(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        vector<TreeNode*> vec;
        inorder(root, vec);
        for(int i = 0; i < vec.size() - 1; i++){
            vec[i]->right = vec[i+1];
            vec[i]->left = NULL;
        }
        vec[vec.size()-1]->left = NULL;
        return vec[0];
    }
    void inorder(TreeNode* root, vector<TreeNode*>& vec){
        if(root!=NULL){
            inorder(root->left, vec);
            vec.emplace_back(root);
            inorder(root->right, vec);
        }
    }
};