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
    vector<int> nums;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        Aft(root);
        return nums;
    }
    void Aft(TreeNode* root){
        if(root!=nullptr){
            Aft(root->left);
            Aft(root->right);
            nums.push_back(root->val);
        }
    }
};