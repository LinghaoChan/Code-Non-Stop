#include <bits/stdc++.h>
using namespace std;

int adjacencyTable[100][100] = {0};
int visit[100] = {0};
int isInStack[100] = {0};
int id = 0;
stack<int> st1, st2;
vector<vector<int>> ans;
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

void dfs(int num, vector<int>& vec){
	id++;
	visit[num] = id;
	st1.push(num);
	st2.push(num);
	int node;
	for(int i = 1; i <= adjacencyTable[num][0]; i++){
		node = adjacencyTable[num][i];
		if(visit[node] == 0){
			dfs(node, vec);
		}else if(isInStack[node]==0){
			while(visit[st2.top()] > visit[node]){
				st2.pop();
			}
		}
	}
	if(num == st2.top()){
		while(num != st1.top()){
			vec.emplace_back(st1.top());
			isInStack[st1.top()] = 1;
			st1.pop();
		}
		vec.emplace_back(num);
		isInStack[num] = 1;
		st1.pop();
		st2.pop();
		ans.emplace_back(vec);
		vec = {};
	}
}

int main(int argc, char const *argv[])
{
	for(int i = 0; i < m; i++){
		int from = E[i][0], to = E[i][1];
		adjacencyTable[from][++adjacencyTable[from][0]] = to;
	}
	for(int i = 1; i <= n; i++){
		if(visit[i]==0){
			vector<int> vec;
			dfs(i, vec);
		}
	}
	for(auto item : ans){
		for(int number :item){
			cout<<number<<" ";
		}
		cout<<endl;
	}
	return 0;
}
