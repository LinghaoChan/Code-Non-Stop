class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int i, j;
        vector<int> n;
        for(i = 0; i < nums.size(); i++){
            int sum = 0;
            for(j = 0; j < nums.size(); j++){
                if(i!=j && nums[i] > nums[j]){
                    sum++;
                }
            }
            n.emplace_back(sum);
        }
        return n;
    }
};
