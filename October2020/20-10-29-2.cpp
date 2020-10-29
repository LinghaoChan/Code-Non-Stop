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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, int> m;
        vector<TreeNode*> vec;
        dfs(root, vec, m);
        return vec;
    }
    string dfs(TreeNode* root, vector<TreeNode*>& vec, map<string, int>& m){
        if(root==nullptr){
            return "#";
        }
        string s = to_string(root->val) + " " + dfs(root->left, vec, m) + " " + dfs(root->right, vec, m);
        if(m[s]==1){
            vec.emplace_back(root);
        }
        m[s]++;
        return s;
    }
};