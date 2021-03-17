#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int main()
{
	int V, n;
	cin>>V>>n;
	int vi[20001]={0};
 	for(int i = 1; i <= n; i++){
 		cin>>vi[i];
	}
	int dp[20001]={0};
	for(int i = 1; i <= n; i++){
		for (int j = V; j >= vi[i]; j--)
		{
			dp[j] = max(dp[j], dp[j-vi[i]]+vi[i]);
		}
	}
	cout<<V-dp[V]; 
	return 0;
}
