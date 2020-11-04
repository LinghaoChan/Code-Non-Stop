class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vec;
        if(nums.size()<4){
            return vec;
        }
        sort(nums.begin(), nums.end());
        int i, j;
        for(i = 0; i < nums.size() - 3; i++){
            for(j = i + 1; j < nums.size() - 2; j++){
                int x = j + 1, y = nums.size()-1;
                int sum = target - nums[i] - nums[j];
                while(x < y){
                    // cout<<i<<" "<<j<<" "<<x<<" "<<y<<"    ";
                    if(nums[x] + nums[y] == sum){
                        if(invec(vec, {nums[i], nums[j], nums[x], nums[y]}))
                        vec.push_back({nums[i], nums[j], nums[x], nums[y]});
                    }
                    if(nums[x] + nums[y] < sum){
                        x++;
                    }else{
                        y--;
                    }
                }
                // cout<<endl;
            }
        }
        return vec;
    }
    bool invec(vector<vector<int>> vec, vector<int> v){
        for(auto i : vec){
            if(i==v){
                return false;
            }
        }
        return true;
    }
};