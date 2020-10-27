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
    int diameterOfBinaryTree(TreeNode* root) {
        int num = 0;
        find(root, num);
        return num;
    }
    int find(TreeNode* root, int& num){
        if(root==NULL){
            return 0;
        }
        int left = find(root->left, num);
        int right = find(root->right, num);
        num = max(left+right, num);
        return 1 + max(left, right);
    }
};