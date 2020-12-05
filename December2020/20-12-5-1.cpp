class Solution {
public:
    int maxPower(string s) {
        int len = s.length();
        char ch = s[0];
        int max = 0;
        int l = 0;
        for(int i = 0; i<len; i++){
            if(ch!=s[i]){
                ch = s[i];
                l = 1;
            } else{
                l++;
                if(l>max){
                    max = l;
                }
            }
        }
        return max;
    }
};