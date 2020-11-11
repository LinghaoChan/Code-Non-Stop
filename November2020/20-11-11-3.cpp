class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1, -1};
        }
        int left = findleft(nums, target);
        int right = findright(nums, target);
        if(left>=nums.size()||nums[left]!=target){
            return {-1, -1};
        }
        return {left, right-1};
    }
    int findleft(vector<int> nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left!=right){
            int mid = (left+right)/2;
            if(nums[mid]>=target){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
    int findright(vector<int> nums, int target){
        int lo = 0;
        int hi = nums.size();

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }

        return lo;
    }
};