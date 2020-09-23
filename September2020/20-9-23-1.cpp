/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> vec;
        pre(root, vec);
        return vec;
    }
    void pre(Node* root, vector<int>& vec){
        if(root!=nullptr){
            vec.push_back(root->val);
            int i;
            for(i=0;i<(root->children).size();i++){
                pre((root->children)[i], vec);
            }
        }
    }
};