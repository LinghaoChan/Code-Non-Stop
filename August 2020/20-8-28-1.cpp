#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;

bool judgeCircle(string moves) {
	int len = moves.length();
	int i, left = 0, up =0;
	for(i  = 0;i <len; i++){
		if(moves[i]=='L'){
			left++;
		} else if(moves[i]=='R'){
			left--;
		} else if(moves[i]=='D'){
			up--;
		} else{
			up++;
		}
	}
	return (left == 0 && up == 0);
}

int main(){
	cout<<judgeCircle("LL");
	
	return 0;
} 
