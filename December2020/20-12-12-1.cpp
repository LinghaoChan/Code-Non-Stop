class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0) return 0;
        int res = 0;
        for(int i = s.size() -1; i >= 0; i--){
            if(s[i] == ' ' && res == 0)
                continue;
            else if(s[i] == ' ')
                return res;
            else res++;
        }
        return res;
    }
};