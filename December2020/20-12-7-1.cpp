class Solution {
public:
    string convertToTitle(int n) {
        string s;
        if(n > 26){
            s += convertToTitle((n-1)/26);
        }
        s+='A'+(n-1)%26;
        return s;
    }
};