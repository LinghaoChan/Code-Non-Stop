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
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        vector<int> vec;
        inorder(root, vec);
        for(int i = 0; i < vec.size()-1; i++){
            if(vec[i] >= vec[i+1]) return false;
        }
        return true;
    }
    void inorder(TreeNode* root, vector<int>& vec){
        if(root!=NULL){
            inorder(root->left, vec);
            vec.emplace_back(root->val);
            inorder(root->right, vec);
        }
    }
};