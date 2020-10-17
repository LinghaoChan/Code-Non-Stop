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
    vector<int> largestValues(TreeNode* root) {
        vector<int> final_vec;
        if(root==nullptr)   return final_vec;
        vector<int> tmp = {root->val};
        vector<TreeNode*> tmpnodes = {root};
        vector<TreeNode*> tt = {};
        while(!tmpnodes.empty()){
            int max = INT_MIN;
            for(auto num : tmp){
                if(num > max)   max = num;
            }
            final_vec.emplace_back(max);
            tmp = {};
            for(auto node : tmpnodes){
                if(node->left!=nullptr){
                    tt.emplace_back(node->left);
                    tmp.emplace_back(node->left->val);
                }
                if(node->right!=nullptr){
                    tt.emplace_back(node->right);
                    tmp.emplace_back(node->right->val);
                }
            }
            tmpnodes = tt;
            tt = {};
        }
        return final_vec;
    }
};