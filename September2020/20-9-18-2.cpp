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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        string s = "";
        DFS(s,root,vec);
        return vec;
    }
    void DFS(string s, TreeNode* root, vector<string>& vec){
        if(root!=nullptr){
            s += to_string(root->val);
            if(root->left==nullptr && root->right==nullptr){
                vec.push_back(s);
            } else{
                s += "->";
                DFS(s,root->left,vec);
                DFS(s,root->right,vec);
            }
        }
    }
};