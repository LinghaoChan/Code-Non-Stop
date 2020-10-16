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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> all_path;
        dfs(root, sum, path, all_path);
        return all_path;
    }
    void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& all_path){
        if(root == NULL){
            return ;
        }
        sum -= root->val;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum==0){
            all_path.push_back(path);
        }
        dfs(root->left, sum, path, all_path);
        dfs(root->right, sum, path, all_path);
        path.pop_back();
    }
};