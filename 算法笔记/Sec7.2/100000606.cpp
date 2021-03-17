#include <iostream>
#include <bits/stdc++.h> 
using namespace std;


int main()
{
	int index1, index2;
	int a[10];
	int max = INT_MIN, min = INT_MAX ;
	for(int i = 0; i < 10; i++){
		scanf("%d", &a[i]);
		if(min >= a[i]){
			min = a[i];
			index1 = i;
		}
		if(max <= a[i]){
			max = a[i];
			index2 = i;
		}
	}
	int tmp = a[index2];
	a[index2] = a[9];
	a[9] = tmp;
	tmp = a[index1];
	a[index1] = a[0];
	a[0] = tmp;
	for(int i = 0; i < 10; i++){
		cout<<a[i]<<' ';
	}	
	return 0;
}
