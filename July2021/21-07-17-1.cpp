class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = 0, ret = nums[0];
        for(int i : nums){
            m = max(i, m + i);
            ret = max(ret, m);
        }
        return ret;
    }
};