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
private:
    unordered_map<int, int> map;
public:
    TreeNode* Bulid(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright){
        if(preleft>preright){
            return NULL;
        }
        int preroot = preleft;
        int inroot = map[preorder[preleft]];
        TreeNode* root = new TreeNode(preorder[preroot]);
        root->left = Bulid(preorder, inorder, preleft+1, preleft+(inroot-inleft), inleft, inroot-1);
        root->right = Bulid(preorder, inorder, preleft+(inroot-inleft)+1, preright, inroot+1, preright);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i;
        for(i=0;i<preorder.size();i++){
            map[inorder[i]] = i;
        }
        return Bulid(preorder, inorder, 0, preorder.size()-1, 0, preorder.size()-1);
    }
};