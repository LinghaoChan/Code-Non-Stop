#include<iostream>
using namespace std;

int main()
{
	int n1, n2;
	int tmp;
	cin>>n1;
	cin>>n2;
	int a1[1001]={0};
	int a2[1001]={0};
	int a3[1001]={0};
	int a4[2002]={0};
	for (int i = 0; i < n1; ++i)
	{
		cin>>tmp;
		cin>>ttmp;
		a1[ttmp]=tmp;
	}
	for (int i = 0; i < n2; ++i)
	{
		cin>>tmp;
		cin>>ttmp;
		a2[ttmp]=tmp;
	}
	for (int i = 0; i < 1001; ++i)
	{
		a3[i] = a1[i] + a2[i];
		if(a3[i]!=0){
			cout<<a3[i]<<" "<<i<<" ";
		}
	}

	return 0;
}
