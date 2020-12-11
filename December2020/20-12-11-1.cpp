class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> tmp;
        dfs(candidates, tmp, target, 0, ret);
        return ret;
    }

    void dfs(vector<int>& candidates, vector<int>& tmp, int target, int index, vector<vector<int>>& ret){
        if(index == candidates.size()){
            return;
        }
        if(target==0){
            ret.emplace_back(tmp);
            return;
        }
        dfs(candidates, tmp, target, index+1, ret);
        if(target>=candidates[index]){
            tmp.emplace_back(candidates[index]);
            dfs(candidates, tmp, target-candidates[index], index, ret);
            tmp.pop_back();
        }

    }
};