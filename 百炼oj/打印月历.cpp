#include<iostream>
using namespace std;

int mm[13]={0, 31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isrun(int year){
	if((year%4==0 && year%100!=0) || (year%400==0))
		return true;
	else
		return false;
}


int main()
{
	int year, month;
	cin>>year>>month;
	cout<<"Sun Mon Tue Wed Thu Fri Sat"<<endl;
	int days = 0;
	for(int i = 1990; i < year; i++){
		if(isrun(i)){
			days += 366;
		}else{
			days += 365;
		}
	}
	for(int i = 1; i < month; i++){
		if(i!=2){
			days += mm[i];
		}else{
			if(isrun(year)){
				days+=29;
			}else{
				days+=28;
			}
		}
	}
	int begin = (days+1)%7;
//	cout<<begin;
	int count = mm[month];
	if(count==-1){
		if(isrun(year)){
			count=28;
		}else{
			count=29;
		}
	}
	for(int i = 0; i < begin; i++){
		cout<<"    ";
	}
	for(int i = 1; i <= count; i++){
		if(begin==0)cout<<endl;
		else {
			if(i!=1)
			cout<<" ";
		}
		if(i<10){
			cout<<"  "<<i;
		}else{
			cout<<" "<<i;
		}
		begin = (begin+1)%7;

	}
	return 0;
}
