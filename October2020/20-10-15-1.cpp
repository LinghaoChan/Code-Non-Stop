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
        vector<Node*> vec1, vec2;
        vec1.push_back(root);
        while(vec1[0]!=NULL){
            for(int i = 0; i < vec1.size(); i++){
                //cout<<vec1[i]->val<<' ';
                vec2.push_back(vec1[i]->left);
                vec2.push_back(vec1[i]-> right);
                if(i<vec1.size()-1)
                vec1[i]->next = vec1[i + 1];
            }
            vec1 = vec2;
            vec2 = {};
        }
        return root;
    }
};