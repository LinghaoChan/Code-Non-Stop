class Solution {
public:
    int climbStairs(int n) {
        if(n<2){
            return n;
        }
        int m = 0, q = 0, p = 1;
        for(int i = 0; i < n; i++){
            m = q;
            q = p;
            p = m + q;
        }
        return p;
    }
};