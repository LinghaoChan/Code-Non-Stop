class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> vec;
        int a = nums.size()/2;
        for(int i = 0; i < a; i++){
            vec.emplace_back(nums[i]);
            vec.emplace_back(nums[i + a]);
        }
        return vec;
    }
};