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
        vector<vector<int>> final_vec;
        vector<int> tmp_vec;
        dfs(root, sum, final_vec, tmp_vec);
        return final_vec;
    }
    void dfs(TreeNode* root, int sum, vector<vector<int>>& final_vec, vector<int> tmp_vec){
        if(root!=NULL){
            sum -= root->val;
            tmp_vec.emplace_back(root->val);
            if(sum == 0 && root->left==NULL && root->right == NULL){
                final_vec.emplace_back(tmp_vec);
                tmp_vec.pop_back();
            }
            dfs(root->left, sum, final_vec, tmp_vec);
            dfs(root->right, sum, final_vec, tmp_vec);
        }
    }
};