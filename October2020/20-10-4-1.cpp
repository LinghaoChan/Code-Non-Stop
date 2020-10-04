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
    int kthLargest(TreeNode* root, int k) {
        vector<int> vec;
        mindthrough(root, vec);
        int pointer = 1;
        if(vec.size()==1)return vec[0];
        int i = vec.size()-1;
        while(k!=pointer){
            i--;
            if(vec[i]!=vec[i+1]){
                pointer++;
            }
        }
        return vec[i];
    }
    void mindthrough(TreeNode* root, vector<int>& vec){
        if(root!=NULL){
            mindthrough(root->left, vec);
            vec.push_back(root->val);
            mindthrough(root->right, vec);
        }
    }
};