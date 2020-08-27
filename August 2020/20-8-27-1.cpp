#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;
bool isValid(string s) {
    vector<char> vec;
	int i;
	for(i = 0; i < s.length(); i++){
		if(vec.size() == 0){
			vec.push_back(s[i]);
		}
		else{
			if(s[i]=='}' || s[i]==']' || s[i]==')'){
				if(vec[vec.size()-1]=='{'&&s[i]=='}'){
					vec.pop_back();
				} else if(vec[vec.size()-1]=='['&&s[i]==']'){
					vec.pop_back();
				} else if(vec[vec.size()-1]=='('&&s[i]==')'){
					vec.pop_back();
				} else if(vec[vec.size()-1]=='}'||vec[vec.size()-1]==']'||vec[vec.size()-1]==')'){
					vec.push_back(s[i]);
				} else{
					return false;
				}
			}else{
				vec.push_back(s[i]);
			}
		} 
		int j;
		for(j=0;j<vec.size();j++){
			cout<<vec[j]<<" ";
		}
		cout<<endl;
	} 
	if(vec.size()==0) return true;
	else return false;
}


int main(){
	cout<<isValid("[])");
	
	return 0;
} 
