class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()){
            return nums;
        }
        vector<int> num2;
        int length=nums.size();
        int multiply=1;
        int i;
        for(i=0;i<length;i++){
            if(i!=0)
            multiply*=nums[i-1];
            num2.push_back(multiply);
            //cout<<multiply<<' ';
        }
        multiply = 1;
        for(i=length-1;i>=0;i--){
            if(i!=length-1)
            multiply*=nums[i+1];
            num2[i]*=multiply;
        }
        return num2;
    }
};