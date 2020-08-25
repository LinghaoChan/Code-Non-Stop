#include <iostream>
using namespace std;
bool isPalindrome(int x) {
	if(x == 0) return true;
	if(x < 0) return false;
    int arr[11];
    int i = 0;
    while(x!=0){
    	arr[i] = x % 10;
    	x /= 10;
    	i++;
	}
	for(int j = 0;j <= i/2; j++){
		if (arr[j] != arr[i-j-1]){
			return false;
		}
	}
	return true;
}
int main(){
	cout<<isPalindrome(9);
	
	return 0;
} 
