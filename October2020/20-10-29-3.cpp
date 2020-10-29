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
    map<int, int> m;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright){
        if(preleft > preright){
            return NULL;
        }
        int preroot = preorder[preleft];
        int inroot_index = m[preroot];
        TreeNode* root = new TreeNode(preroot);
        int left_size = inroot_index - inleft;
        root->left = build(preorder, inorder, preleft + 1, left_size + preleft, inleft, inroot_index - 1);
        root->right = build(preorder, inorder, preleft + left_size + 1, preright, inroot_index + 1, inright);
        return root;
    }
};