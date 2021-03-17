#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

class Node{
	public:
		int add;
		int num;
		int next;
	Node(int a, int b, int c){
		add = a;
		num = b;
		next = c;
	}
}; 


int main()
{
	vector<Node> vec;
	Node no[100005] = Node(0, 0, 0);
	int n;
	int first;
	cin>>n>>first;
	for(int i = 0; i < n; i++){
		int a, b, c;
		cin >>a>>b>>c;
		Node node = Node(a, b, c);
		no[a] = node;
//		cout<<vec[i].add<<endl<<vec[i].num<<endl<<vec[i].next<<endl;
	}
	while(first!=-1){
		vec.emplace_back(no[first]);
		first = no[first].next;
	}
	if(vec.size()==0){
		cout<<"0 -1\n";
		return 0;
	}
	sort(vec.begin(), vec.end(), [](Node a, Node b){
		return a.num < b.num;
	});
//	int addtmp=vec[0].add, nexttmp;
	cout<<vec.size()<<' ';
	printf("%05d\n", vec[0].add);
	for(int i = 0; i < vec.size(); i++){
		printf("%05d ", vec[i].add);
		cout<<vec[i].num<<' ';
		if(i!=vec.size()-1){
			printf("%05d\n", vec[i+1].add);
		}
		else{
			cout<<-1;
		}
	}
	return 0;
}
