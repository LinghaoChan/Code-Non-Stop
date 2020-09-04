class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<=nums[0]){
            return 0;
        }
        int i;
        for(i = 1;i<nums.size();i++){
            if(target>nums[i - 1] && target <=nums[i]){
                return i;
            }
        }
        return i;
    }
};