class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<char> vec1, vec2;
        int i;
        for(i=0;i<s.size();i++){
            vec1.push_back(s[i]);
        }
        for(i=0;i<t.size();i++){
            vec2.push_back(t[i]);
        }
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        for(i=0;i<s.size();i++){
            if(vec1[i]!=vec2[i])
                return vec2[i];
        }
        return vec2[i];
    }
};