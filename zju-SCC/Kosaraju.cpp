#include <bits/stdc++.h>
using namespace std;


int adjacencyTableOrignal[100][100] = {0};
int adjacencyTableTrans[100][100] = {0};
int visitFirst[100] = {0};
int visitSecond[100] = {0};
int classification[100] = {0};
stack<int> st;
int labels = 0;
int n = 9, m = 12;
int E[12][2] = {
	{1, 2},
	{2, 3},
	{3, 1},
	{1, 4},
	{4, 5},
	{5, 6},
	{5, 7},
	{7, 6},
	{6, 4},
	{5, 8},
	{8, 9},
	{9, 8},
};


void dfsFirst(int num){
	int node;
	for(int i = 1; i <= adjacencyTableOrignal[num][0]; i++){
		node = adjacencyTableOrignal[num][i];
		if(visitFirst[node] == 0){
			visitFirst[node] = 1;
			dfsFirst(node);
		}
	}
	st.push(num);
//	cout<<num<<" ";
}

void dfsSecond(int num, vector<int>& vec){
	int node;
	classification[num] = labels;
	vec.emplace_back(num);
//	cout<<num<<endl;
	for(int i = 1; i <= adjacencyTableTrans[num][0]; i++){
		node = adjacencyTableTrans[num][i];
		if(visitSecond[node]==0){
			visitSecond[node] = 1;
			dfsSecond(node, vec);
		}
	}
}

int main(int argc, char const *argv[])
{
	for(int i = 0; i < m; i++){
		int from = E[i][0], to = E[i][1];
		adjacencyTableOrignal[from][++adjacencyTableOrignal[from][0]] = to;
		adjacencyTableTrans[to][++adjacencyTableTrans[to][0]] = from;
	}
	for(int i = 1; i <= n; i++){
		if(visitFirst[i]==0){
			visitFirst[i] = 1; 
			dfsFirst(1);
		}
	}
	vector<vector<int>> ans;
	while(!st.empty()){
		int top = st.top();
//		cout<<top<<"  ";
		st.pop();
		if(visitSecond[top]==0){
			visitSecond[top] = 1;
			labels++;
			vector<int> tmp;
			dfsSecond(top, tmp);
			ans.emplace_back(tmp);
		}
	}
//	cout<<endl;
	for(auto item : ans){
		for(int number :item){
			cout<<number<<" ";
		}
		cout<<endl;
	}
	return 0;
}
