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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2, vec;
        inorder(root1, vec1);
        inorder(root2, vec2);
        int i=0, j=0;
        int size1 = vec1.size();
        int size2 = vec2.size();
        while(i<size1 && j<size2){
            if(vec1[i]<vec2[j]){
                vec.push_back(vec1[i]);
                i++;
            }else{
                vec.push_back(vec2[j]);
                j++;
            }
        }
        if(i<size1){
            for(int m = i; m<size1; m++){
                vec.push_back(vec1[m]);
            }
        }else if(j<size2){
            for(int n = j; n<size2; n++){
                vec.push_back(vec2[n]);
            }
        }
        return vec;
    }
    void inorder(TreeNode* root, vector<int>& vec){
        if(root!=NULL){
            inorder(root->left, vec);
            vec.push_back(root->val);
            inorder(root->right, vec);
        }
    }
};