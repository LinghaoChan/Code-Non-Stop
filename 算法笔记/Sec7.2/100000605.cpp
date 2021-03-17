#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void fun(string str){
	double num = 0.0;
	char op = '+';
	vector<double> vec={0};

	for (auto s : str){
		if(isdigit(s)){
			num = num * 10 + s - '0';
		}else{
			if(s == ' '){
				continue;
			}
			if(op == '+'){
				vec.emplace_back(num);
			} else if(op == '-'){
				vec.emplace_back(-num);
			} else if(op == '*'){
				double tmp = vec.back();
				vec.pop_back();
				vec.emplace_back(tmp * num);
			} else{
				double tmp = vec.back();
				vec.pop_back();
				vec.emplace_back(tmp / num);
			}
			num = 0;
			op = s;
		}
	}
	double sum = 0;
	if(op == '+'){
		vec.emplace_back(num);
	} else if(op == '-'){
		vec.emplace_back(-num);
	} else if(op == '*'){
		double tmp = vec.back();
		vec.pop_back();
		vec.emplace_back(tmp * num);
	} else{
		double tmp = vec.back();
		vec.pop_back();
		vec.emplace_back(tmp / num);
	}
	for(int i = 0; i < vec.size(); i++){
		sum += vec[i];
	}

	printf("%.2f\n", sum);
}

int main()
{
	while(1){
		string str;
		char sss[1000];
		gets(sss);
		str = sss;
		if(str=="0"){
			break;
		}
		fun(str);
	}

	return 0;
}
