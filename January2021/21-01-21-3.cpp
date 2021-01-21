class Solution {
public:
    int calculate(string s) {
        char op = '+';
        vector<int> v;
        string tmp = "";
        for(auto i : s){
            if(i==' '){
                continue;
            }
            if(!isdigit(i)){
                if(op=='+'){
                    v.emplace_back(stoi(tmp));
                    tmp="";
                }else if(op=='-'){
                    v.emplace_back(-stoi(tmp));
                    tmp="";
                }else if(op=='*'){
                    int a = v.back();
                    v.pop_back();
                    int b = stoi(tmp);
                    v.emplace_back(a*b);
                    tmp="";
                }else if(op=='/'){
                    int a = v.back();
                    v.pop_back();
                    int b = stoi(tmp);
                    v.emplace_back(a/b);
                    tmp="";
                }
                op = i;

            }
            else{
                tmp+=i;
            }
        }
        if(op=='+'){
            v.emplace_back(stoi(tmp));
            tmp="";
        }else if(op=='-'){
            v.emplace_back(-stoi(tmp));
            tmp="";
        }else if(op=='*'){
            int a = v.back();
            v.pop_back();
            int b = stoi(tmp);
            v.emplace_back(a*b);
        }else if(op=='/'){
            int a = v.back();
            v.pop_back();
            int b = stoi(tmp);
            v.emplace_back(a/b);
        }
        int sum = 0;
        for(int item : v){
            sum += item;
        }
        return sum;
    }
};