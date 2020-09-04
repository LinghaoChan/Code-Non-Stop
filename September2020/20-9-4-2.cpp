class Solution {
public:
    string removeDuplicates(string S) {
        vector<char> st;
        int i;
        char ss[20002];
        for(i = 0; i < S.length();i++){
            if(st.empty()){
                st.push_back(S[i]);
            }else{
                if(st[st.size()-1] == S[i]){
                    st.pop_back();
                }else{
                    st.push_back(S[i]);
                }
            }
        }
        for(i = 0;i < st.size();i++){
            ss[i] = st[i];
        }
        ss[i] = '\0';
        string s = ss;
        return s;
    }
};