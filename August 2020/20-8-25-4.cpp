#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string longestCommonPrefix(vector<string> & strs) {
	if (strs.size()==0) return "";
    int i;
    string str = strs[0];
    int sum = 0;	
	int j=0;
    for(i = 0;i < str.length();i++){
    
    	for(j=0;j<strs.size();j++){
			string strcmp = strs[j];
			if(strs[j].length()==i) return string(str, 0, sum);
			char ch = strcmp[i];
			if(str[i] != strcmp[i]){
				return string(str, 0, sum);
			}
		}
		sum++;
	}
	return string(str, 0, sum);
}



int main(){
	vector<string> str = {"flower","flow","fight"};
	cout<<longestCommonPrefix(str); 
	
	return 0;
} 
