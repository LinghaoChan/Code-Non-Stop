class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> final_vec = {};
        if(nums.size()==0){
            return {{}};
        }
        for(int i = 0; i < nums.size(); i++){
            vector<int> tt = {nums[i]};
            final_vec.emplace_back(tt);          
        }
        for(int i = 0; i < nums.size()-1; i++){
            insort(nums, final_vec);            
        }
        return final_vec;
    }
    void insort(vector<int>& nums, vector<vector<int>>& final_vec){
        // cout<<final_vec.size()<<endl;
        vector<vector<int>> tmp;
        for(int i=0; i<final_vec.size(); i++){
            auto t = final_vec[i];
            for(int j = 0; j < nums.size(); j++){
                if(isIn(t, nums[j])){
                    vector<int> tt = t;
                    tt.emplace_back(nums[j]);
                    tmp.emplace_back(tt);
                }
            }
        }
        final_vec = tmp;
    }
    bool isIn(vector<int>& nums, int n){
        for(auto i : nums){
            if(i == n){
                return false;
            }
        }
        return true;
    }
};