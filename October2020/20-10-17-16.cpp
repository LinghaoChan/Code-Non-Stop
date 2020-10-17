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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> AllNodes;
        if(root==NULL)  return AllNodes;
        vector<int> NodesVal = {root->val};
        vector<TreeNode*> Nodes = {root}; 
        vector<TreeNode*> NodesTmp; 
        while(!Nodes.empty()){
            AllNodes.emplace_back(NodesVal);
            NodesVal = {};
            for(auto nodes : Nodes){
                if(nodes->left!=NULL){
                    NodesVal.emplace_back(nodes->left->val);
                    NodesTmp.emplace_back(nodes->left);                    
                }
                if(nodes->right!=NULL){
                    NodesVal.emplace_back(nodes->right->val);
                    NodesTmp.emplace_back(nodes->right);                
                }

            }
            Nodes = NodesTmp;
            NodesTmp = {};
        }
        return AllNodes;
    }
};