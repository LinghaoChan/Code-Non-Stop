#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int n;
	int t;
	int i;
	scanf("%d", &n);
	int sum = 0, maxsum = 0; 
	for(i = 0; i < n; i++){
		cin>>t;
		sum += t;
		if(sum > maxsum){
			maxsum = sum;
		}
		if(sum < 0){
			sum = 0;
		}
	}
	cout<<maxsum;
	return 0;
}
