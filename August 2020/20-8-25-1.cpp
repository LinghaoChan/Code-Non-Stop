#include <iostream>
using namespace std;
int absolute(int x){
	int rev=0;
	while(x!=0){
		if(rev > INT_MAX/10 || rev < INT_MIN/10) 
            return 0;
        else{
    		rev = 10 * rev + (x % 10);
			x /= 10;    	
		}

	}
	return rev;
}
int reverse(int x){
	if (x==0){
		return x;
	}
	else if(x<0){
		return (absolute(x));
	}
	else{
		return (absolute(x));
	}
}
int main(){
	cout<<absolute(-1230);
	
	return 0;
} 
