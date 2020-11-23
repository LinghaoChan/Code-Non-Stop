class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = INT_MAX;
        for(int num : nums){
            m = min(num, m);
        }
        int re = 0;
        for(int num : nums){
            re += (num - m);
        }
        return re;
    }
};