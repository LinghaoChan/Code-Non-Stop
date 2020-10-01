class Solution {
public:
    int firstUniqChar(string s) {
        for(int i = 0; i<s.size(); i++){
            if(s.find_first_of(s[i])==s.find_last_of(s[i])) return i;
        }
        return -1;
    }
};