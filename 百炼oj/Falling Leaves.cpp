#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

class Node
{
public:
	char value;
	Node* left;
	Node* right;
	int index;
	Node(char v, int in, Node* l = nullptr, Node* r = nullptr){
		this->value = v;
		this->left = l;
		this->right = r;
		this->index = in;
	}
	
};


void addNode(Node* root, Node* node){
	if(root!=nullptr){
		if(node->value < root->value){
			if(root->left == nullptr){
				if(root->index == node->index){
					return;
				}else{
					root->left = node;
				}
			}else{
				addNode(root->left, node);				
			}

		}else{
			if(root->right == nullptr){
				if(root->index == node->index){
					return;
				}else{
					root->right = node;
				}
			}else{
				addNode(root->right, node);				
			}
		}
	}
}

void preorder(Node* root){
	if(root!=nullptr){
		cout<<root->value;
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	int flag = 1;
	while(1){
		vector<string> vec;
		string str;	
		while(1){
			cin>>str;
			if(str=="*" || str == "$"){
				break;
			}
			vec.emplace_back(str);
		}
		if(str == "$"){
			flag = 0;
		}



		Node* root = nullptr;
		int size = vec.size();
		for(int i = size - 1; i >= 0; i--){
			string s = vec[i];
			for(int j = s.length() - 1; j >= 0; j--){
				char ch = s[j];
				if(root==nullptr){
					root = new Node(ch, i, nullptr, nullptr);
				}else{
					Node* node = new Node(ch, i, nullptr, nullptr);
					addNode(root, node);
				}
			}
		}
		preorder(root);


		if(flag == 0){
			break;
		}else{
			cout<<endl;
		}
	}
	return 0;
}
