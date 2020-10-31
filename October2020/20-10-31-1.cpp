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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> dp;
        if(N & 1 == 0) return dp;
        if(N == 1) {dp.push_back(new TreeNode(0));return dp;}
        for(int i=1;i<=N-2;i+=2){
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(N-1-i);
            for(int j=0;j<left.size();++j){
                for(int k=0;k<right.size();++k){
                    TreeNode *root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    dp.push_back(root);
                }
            }
        }
        return dp;
    }
};