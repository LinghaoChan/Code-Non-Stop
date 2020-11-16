class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()){
            return false;
        }
        unordered_map<char, int> need, window;
        int len = s1.size();
        int size2 = s2.size();
        for(int i = 0; i < len; i++){
            char ch1 = s1[i];
            need[ch1]++;
        }
        int valid = 0;
        for(int i = 0; i < len; i++){
            char ch = s2[i];
            if(need.count(ch)){
                window[ch]++;
                if(need[ch]==window[ch]){
                    valid++;
                }
            }
        }
        // cout<<need.size();
        if(valid == need.size()){
            return true;
        }
        int pointer = len;
        while(pointer < s2.size()){
            char ch_before = s2[pointer - len];
            if(need.count(ch_before)){
                if(window[ch_before]==need[ch_before]){
                    valid--;
                }                
            }
            window[ch_before]--;
            char ch_after = s2[pointer];
            window[ch_after]++;
            if(need.count(ch_after)){
                if(window[ch_after]==need[ch_after]){
                    valid++;
                }

            }
            // cout<<window['a']<<"  "<<window['b']<<"  "<<valid <<endl;
            if(valid==need.size()){
                return true;
            }
            pointer++;
        }
        return false;
    }
};