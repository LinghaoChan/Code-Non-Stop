#include <bits/stdc++.h>
using namespace std;

int adjacencyTable[100][100] = {0};
int firstVisit[100] = {0};
int secondVisit[100] = {0};
int isInStack[100] = {0};
int id = 0;
stack<int> st;
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
	st.push(num);
	id++;
	firstVisit[num] = id;
	secondVisit[num] = id;
	int node;
	for(int i = 1; i <= adjacencyTable[num][0]; i++){
		node = adjacencyTable[num][i];
		if(firstVisit[node] == 0){
			dfs(node, vec);
			secondVisit[num] = min(secondVisit[num], secondVisit[node]);
		}else if(isInStack[node]==0){
			secondVisit[num] = min(secondVisit[num], secondVisit[node]);
		}
	}
	if(firstVisit[num] == secondVisit[num]){
		int tmp;
		while(tmp != num){
			tmp = st.top();
			isInStack[tmp] = 1;
			st.pop();
			vec.emplace_back(tmp);
		}
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
		if(firstVisit[i]==0){
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
