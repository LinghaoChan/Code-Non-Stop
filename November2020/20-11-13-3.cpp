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
    int ans = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        fun(root);
        return ans;
    }
    int fun(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left = max(0, fun(root->left));
        int right = max(0, fun(root->right));
        // cout << left <<" "<< right << " " << root->val<<endl;
        if(left + right + root->val > ans){
            ans = left + right + root->val;
        }
        return max(left, right) + root->val;
    }
};