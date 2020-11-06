class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(target == nums[0]){
            return 0;
        }else if(target > nums[0]){
            for(int i = 1; i < nums.size(); i++){
                if(nums[i] == target){
                    return i;
                }
                if(nums[i] < nums[i-1]){
                    return -1;
                }
            }
            return -1;
        }else{
            for(int i = nums.size() - 1; i > 0; i--){
                if(nums[i] == target){
                    return i;
                }
                if(nums[i] < nums[i-1]){
                    return -1;
                }
            }
            return -1;
        }
    }
};