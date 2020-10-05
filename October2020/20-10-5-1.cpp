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
    int countNodes(TreeNode* root) {
        vector<int> vec;
        through(root, vec);
        return vec.size();
    }
    void through(TreeNode* root, vector<int>& vec){
        if(root!=NULL){
            through(root->left, vec);
            vec.push_back(root->val);
            through(root->right, vec);
        }
    }
};