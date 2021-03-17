#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin>>a>>b;
    int s = a+b;
    int flag = 0;
    if(s<0){
        flag = 1;
    }
    s = abs(s);
    int q = s%1000;
    int w = (s/1000)%1000;
    int e = (s/1000000)%1000;
    if(flag==1){
        cout<<"-";
    }
    if(e==0){
        if(w==0){
            cout<<q;
        }else{
            cout<<w<<",";
            printf("%03d",q);
        }
    }else{
        cout<<e<<",";
        printf("%03d,%03d", w, q);
    }
    return 0;
}