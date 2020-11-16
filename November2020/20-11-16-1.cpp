class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for(char c : t){
            need[c]++;
        }
        int left = 0, right = 0;
        int valid = 0;
        int len = INT_MAX;
        int ans_left = 0;
        while(right < s.size()){
            char c = s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]){
                    valid++;
                }
            }
            while(valid==need.size()){
                // cout<<left<<" "<<right<<endl;
                if(right-left<len){
                    ans_left = left;
                    len = right-left;
                }
                char ch = s[left];
                if(need.count(ch)){
                    window[ch]--;
                    if(window[ch]<need[ch]){
                        valid--;
                    }
                }
                left++;
            }
        }
        return len == INT_MAX ? "" : s.substr(ans_left, len);
    }
};