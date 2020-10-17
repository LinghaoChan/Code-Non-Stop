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
    int pathSum(TreeNode* root, int sum) {
        int s = 0;
        vector<TreeNode*> vec;
        inorder(root, vec);
        for(int i = 0; i < vec.size(); i++){
            dfs(vec[i], sum, s);
        }
        return s;
    }
    void inorder(TreeNode* root, vector<TreeNode*>& vec){
        if(root!=NULL){
            inorder(root->left, vec);
            vec.emplace_back(root);
            inorder(root->right, vec);        
        }
    }
    void dfs(TreeNode* root, int sum, int& s){
        if(root==NULL){
            return ;
        }
        sum -= root->val;
        // cout<<root->val<<' '<<sum<<endl;
        if(sum == 0){
            s++;
        }
        dfs(root->left, sum, s);
        dfs(root->right, sum, s);
    }
};