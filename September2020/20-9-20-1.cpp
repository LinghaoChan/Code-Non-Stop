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
    int getMinimumDifference(TreeNode* root) {
        vector<int> vec;
        preorder(root, vec);
        int i;
        int minus = INT_MAX;
        if(vec.size()<2)
        return 0;
        sort(vec.begin(), vec.end());
        for(i=0;i<vec.size()-1;i++){
            if(abs(vec[i]-vec[i+1])<minus){
                minus = abs(vec[i]-vec[i+1]);
            }
        }
        return minus;
    }
    void preorder(TreeNode* root, vector<int>& vec){
        if(root!=NULL){
            vec.push_back(root->val);
            preorder(root->left, vec);
            preorder(root->right, vec);
        }
    }
};