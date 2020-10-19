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
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        vector<vector<int>> v = levelOrder(root);
        vector<int> vv = v[v.size() - 1];
        int sum = 0;
        for(auto x : vv){
            sum+=x;
        }
        return sum;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> AllNodes;
        if(root==NULL)  return AllNodes;
        vector<TreeNode*> Nodes = {root};
        vector<int> NodesVal = {root->val}; 
        vector<TreeNode*> NodesTmp; 
        int i = 1;
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
            i++;
        }
        return AllNodes;
    }
};