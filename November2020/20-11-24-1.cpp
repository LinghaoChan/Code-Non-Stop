class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int a : nums){
            sum+=a;
        }
        return (n+1)*n/2-sum;
    }
};