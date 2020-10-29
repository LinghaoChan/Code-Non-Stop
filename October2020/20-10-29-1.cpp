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
    int findTilt(TreeNode* root) {
        int sum = 0;
        dfs(root);
        s(root, sum);
        return sum;
    }
    int dfs(TreeNode* root){
        if(root!=nullptr){
            int left = dfs(root->left);
            int right = dfs(root->right);
            root->val += (left + right);
            // cout<<root->val<<' ';
            return root->val;
        }else{
            return 0;
        }
    }
    void s(TreeNode* root, int& sum){
        if(root!=nullptr){
            if(root->left!=nullptr && root->right!=nullptr){
                sum += abs(root->left->val - root->right->val);
            }else if(root->left!=nullptr && root->right==nullptr){
                sum += abs(root->left->val);
            }else if(root->left==nullptr && root->right!=nullptr){
                sum += abs(root->right->val);
            }
            s(root->left, sum);
            s(root->right, sum);
        }
    }
};