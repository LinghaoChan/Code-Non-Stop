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
    vector<vector<int>> all_path;
    vector<int> path;
public:
    int sumNumbers(TreeNode* root) {
        dfs(root);
        int s = 0;
        for(auto vec : all_path){
            int sum = 0;
            for(int j= 0; j<vec.size(); j++){
                sum = vec[j] + sum * 10;
            }
            s += sum;
        }
        return s;
    }
    void dfs(TreeNode* root){
        if(root == NULL){
            return;
        }
        path.emplace_back(root->val);
        if(root->left==NULL && root->right==NULL){
            all_path.emplace_back(path);
        }
        dfs(root->left);
        dfs(root->right);
        path.pop_back();
    }
};