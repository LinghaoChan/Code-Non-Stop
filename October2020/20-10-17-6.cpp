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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> all_nodes;
        if(root == NULL) return all_nodes;
        vector<Node*> layer1 = {root};
        vector<Node*> layer2;
        vector<int> layer;
        while(!layer1.empty()){
            for(auto node : layer1){
                if(!node->children.empty()){
                    for(auto n : node->children){
                        layer2.emplace_back(n);
                    }
                }
                layer.emplace_back(node->val);
            }
            layer1 = layer2;
            all_nodes.emplace_back(layer);
            layer2 = {};
            layer = {};
        }
        return all_nodes;
    }
};