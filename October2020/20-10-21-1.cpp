class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while(j < typed.length()){
            if(name[i] == typed[j]){
                i++;
                j++;
            }else if(i>0 && typed[j] == typed[j - 1]){
                j++;
            }else{
                return false;
            }
        }
        return i == name.length();
    }
};