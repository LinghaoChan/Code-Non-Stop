#include<iostream>
using namespace std;


int main()
{
	int n, k;
	while(1){
		cin>>n>>k;
		if(n==0&&k==0){
			return 0;
		}
		long long M[55]={0};
		M[1] = 1;
		M[0]=1;
		for(int i = 2; i <= n; i++){
			for(int j = 1; j <= k; j++){
				if(i < j){
					break;
				}
				if((j)%10!=4 && (!((j)>=40 && (j)<50))){
					M[i] += M[i - j];
//					cout<<j<<"  "<<i-j<<endl;			
				}

			}
		}
		cout<<M[n]<<endl;
	}



	return 0;
}
