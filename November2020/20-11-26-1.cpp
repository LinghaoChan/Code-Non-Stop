class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(string s : strs){
            string ss = s;
            sort(ss.begin(), ss.end());
            mp[ss].emplace_back(s);
        }
        for(auto i : mp){
            ans.emplace_back(i.second);
        }
        return ans;
    }
};