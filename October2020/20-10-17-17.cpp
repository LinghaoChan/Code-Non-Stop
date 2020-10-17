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
        int i = 1;
        while(!Nodes.empty()){
            if(i%2==0){
                swap(NodesVal);
                AllNodes.emplace_back(NodesVal);
                swap(NodesVal);
            }else{
                AllNodes.emplace_back(NodesVal);
            }
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
    void swap(vector<int>& vec){
        int i = 0, j = vec.size() - 1;
        while(i<j){
            int tmp = vec[j];
            vec[j] = vec[i];
            vec[i] = tmp;
            i++;
            j--;
        }
    }
};