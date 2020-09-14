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
	int maxDepth(Node* root) {
		int max = 0;
        if (!root) 
            return 0;
		if ((root->children).size() == 0)
			return 1;
		vector<int> ch;
		for (int i = 0; i < (root->children).size(); ++i)
			ch.push_back(maxDepth(root->children[i]));
		for (int i = 0; i < ch.size(); i++)
			max = max > ch[i] ? max : ch[i];
		return max + 1;
	}
};