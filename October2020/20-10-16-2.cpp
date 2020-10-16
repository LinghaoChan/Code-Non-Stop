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
    void flatten(TreeNode* root) {
        if(root!=nullptr){
            vector<TreeNode*> vec;
            preorder(root, vec);
            int n = vec.size();
            for(int i = 0; i < n - 1; i++){
                vec[i]->left = nullptr;
                vec[i]->right = vec[i+1];
            }            
        }
    }
    void preorder(TreeNode* &root, vector<TreeNode*>& vec){
        if(root!=nullptr){
            vec.push_back(root);
            preorder(root->left, vec);
            preorder(root->right, vec);
        }
    }
};