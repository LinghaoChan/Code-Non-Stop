class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        for(i = size - 1; i >= 1 ; i--){
            if(nums[i] > nums[i-1]){
                break;
            }
        }
        int flag = i - 1;
        if(flag==-1){
            return reverse(nums.begin(),  nums.end());
        }
        for(i = size - 1; i >= 1 ; i--){
            if(nums[i] > nums[flag]){
                int tmp = nums[flag];
                nums[flag] = nums[i];
                nums[i] = tmp;
                break;
            }
        }
        sort(nums.begin() + flag + 1, nums.end());
    }

};