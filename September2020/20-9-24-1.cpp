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
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> vec;
        preorder(root, vec);
        sort(vec.begin(), vec.end());
        if(vec.size()==0){
            return -1;
        }else{
            int min = vec[0];
            int i;
            for(i=0;i<vec.size();i++){
                if(min<vec[i]){
                    return vec[i];
                }
            }
            return -1;
        }
    }
    void preorder(TreeNode* root, vector<int>& vec){
        if(root!=NULL){
            vec.push_back(root->val);
            preorder(root->left, vec);
            preorder(root->right, vec);            
        }
    }
};