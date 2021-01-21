class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto item : tokens){
            if(item=="+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            } else if(item=="-"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            } else if(item=="*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a*b);
            } else if(item=="/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            } else{
                s.push(stoi(item));
            }
            // cout<<s.top()<<endl;
        }
        return s.top();
    }
};