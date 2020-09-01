class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int lens = S.length(),lent = T.length();
        stack<char> s1={},s2={};
        int i, j;
        for(i = 0;i < lens;i++){
            if(S[i]=='#'){
                if(!s1.empty())
                s1.pop(); 
            }
            else{
                s1.push(S[i]);
            }
        }
        for(i = 0;i < lent;i++){
            if(T[i]=='#'){
                if(!s2.empty())
                s2.pop(); 
            }
            else{
                s2.push(T[i]);
            }
        }
        return Compare(s1, s2);
    }
    bool Compare(stack<char> &S, stack<char> &T){
        int i=0;
        while(!S.empty() || !T.empty()){
            if((S.empty()&&(!T.empty())) || (!S.empty()&&(T.empty()))){
                return false;
            }
            if(S.top() == T.top()){
                S.pop();
                T.pop();
            }else{
                return false;
            }
        }
        return true;
    }
};