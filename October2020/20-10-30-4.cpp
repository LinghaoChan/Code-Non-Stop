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
    string tree2str(TreeNode* t) {
        string s = "";
        create(t, s);
        return s;
    }
    void create(TreeNode* root, string& s){
        if(root!=NULL){
            s = s + to_string(root->val);
            if(root->left!=NULL || root->right!=NULL){
                s += "(";
                create(root->left, s);
                s += ")";
                if(root->right!=NULL){
                    s += "(";
                    create(root->right, s);
                    s += ")";                       
                }else{
                    create(root->right, s);
                }
           
            }

        }
    }
};