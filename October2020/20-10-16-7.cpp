/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)return NULL;
        vector<Node*> vec1, vec2;
        vec1.emplace_back(root);
        while(!vec1.empty()){
            for(int j = 0; j < vec1.size()-1; j++){
                vec1[j]->next = vec1[j+1];
            }
            PushToVec(root, vec1, vec2);
        }
        return root;
    }
    void PushToVec(Node* root, vector<Node*>& vec1, vector<Node*>& vec2){
        if(vec1.empty()){
            return ;
        }
        for(int i = 0; i < vec1.size(); i++){
            if(vec1[i]->left != NULL){
                vec2.emplace_back(vec1[i]->left);
            }
            if(vec1[i]->right != NULL){
                vec2.emplace_back(vec1[i]->right);
            }
        }
        vec1 = vec2;
        vec2 ={};
    }
};