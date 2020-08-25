#include <iostream>
using namespace std;
int evaluate(char x){
    switch(x){
        case 'I':{
            return 1;
            break;
        }
        case 'V':{
            return 5;
            break;
        }
        case 'X':{
            return 10;
            break;
        }
        case 'L':{
            return 50;
            break;
        }
        case 'C':{
            return 100;
            break;
        }
        case 'D':{
            return 500;
            break;
        }
		default:
			return 1000; 
    }
}
int romanToInt(string s) {
    enum Signal {
    	I, V, X, L, C, D, M
	}; 
	Signal sig;
	int i = 0;
	int arr[4000];
	int sum = 0;
	for(i = 0; i < s.length(); i++){
	    arr[i] = evaluate(s[i]);
//	    cout<<arr[i];
	    if(arr[i-1]<arr[i] && i!=0){
	        arr[i-1] *= (-1);
	    }
	    sum += arr[i-1];
	}
	return sum + arr[i-1];
}


int main(){
	cout<<romanToInt("LVIII");
	
	return 0;
} 
