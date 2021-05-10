#include <bits/stdc++.h>
using namespace std;

int adjacencyTable[100][100] = {0};
int id = 0;
int dfn[100] = {0};
int low[100] = {0};
int father[100];
vector<int> ans;
int n = 9, m = 7;
int E[7][2] = {
	{1, 2},
	{1, 3},
	{1, 4},
	{2, 5},
	{5, 3},
	{5, 4},
	{5, 6}
};

void dfs(int num){
	id++;
	dfn[num] = id;
	low[num] = id;
	int childNumber = 0;
	for(int i = 1; i <= adjacencyTable[num][0]; i++){
		int node = adjacencyTable[num][i];
		if(dfn[node] == 0){
			childNumber++;
			father[node] = num;
			dfs(node);
			if(father[num] == -1 && childNumber > 1){
				ans.emplace_back(num);
			}
			if(father[num] != -1 && low[node] >= dfn[num]){
				ans.emplace_back(num);
			}
			if(low[node] > dfn[num]){
				cout<<num<<"   "<<node<<endl;
			}
			low[num] = min(low[num], low[node]);
		}else if(node != father[num]){
			low[num] = min(low[num], low[node]);
		}
	}
}

int main(int argc, char const *argv[])
{
	memset(father, -1, sizeof(father));
	for(int i = 0; i < m; i++){
		int from = E[i][0], to = E[i][1];
		adjacencyTable[from][++adjacencyTable[from][0]] = to;
		adjacencyTable[to][++adjacencyTable[to][0]] = from;
	}
	for(int i = 1; i <= n; i++){
		if(dfn[i]==0){
			dfs(i);
		}
	}
	for(auto item : ans){
		cout<<item<<"  ";
	}
	return 0;
}
