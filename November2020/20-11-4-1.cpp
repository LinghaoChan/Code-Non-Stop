class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int sum;
        for(int index = 0; index < nums.size(); index++){
            int i = 0;
            int tmp = nums[index];
            int j = nums.size() - 1;
            while(i < j){
                if(i!=index && j!=index){
                // cout<<nums[i]<<" "<<nums[j]<<" "<<tmp<<" "<<endl;
                    if(abs(nums[i]+nums[j]+tmp - target) < ans){
                        ans = abs(nums[i]+nums[j]+tmp - target);
                        sum = nums[i]+nums[j]+tmp;
                    }
                    if(nums[i]+nums[j]+tmp < target){
                        i++;
                    }else if(nums[i]+nums[j]+tmp > target){
                        j--;
                    }else{
                        return nums[i]+nums[j]+tmp;
                    }
                }else if(i==index){
                    i++;
                }else{
                    j--;
                }
            }
        }
        return sum;
    }
};