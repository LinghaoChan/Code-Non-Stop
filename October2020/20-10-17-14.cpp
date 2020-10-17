/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> vec = LayerOrder(tree);
        return vec;
    }
    vector<ListNode*> LayerOrder(TreeNode* root){
        vector<ListNode*> AllNodes;
        ListNode* l = new ListNode(root->val);
        vector<TreeNode*> Nodes = {root}; 
        vector<TreeNode*> NodesTmp; 
        while(!Nodes.empty()){
            l = makelist(Nodes);
            AllNodes.emplace_back(l);

            for(auto nodes : Nodes){
                if(nodes->left!=NULL){
                    NodesTmp.emplace_back(nodes->left);                    
                }
                if(nodes->right!=NULL){
                    NodesTmp.emplace_back(nodes->right);                
                }

            }
            Nodes = {};
            Nodes = NodesTmp;

            NodesTmp = {};
        }
        return AllNodes;
    }
    ListNode* makelist(vector<TreeNode*> vec){
        ListNode* l = new ListNode(vec[0]->val); 
        ListNode* list = l;
        for(int i = 1; i < vec.size(); i++){
            ListNode* p = new ListNode(vec[i]->val);
            l->next = p;
            l = p;
        }
        return list;
    }
};