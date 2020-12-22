class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int s = 0;
        for(int i : nums){
            ans = ~s & (ans ^ i);
            s = ~ans & (s ^ i);
        }
        return ans;
    }
};class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int s = 0;
        for(int i : nums){
            ans = ~s & (ans ^ i);
            s = ~ans & (s ^ i);
        }
        return ans;
    }
};