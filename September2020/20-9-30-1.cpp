class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)return true;
        if(n%3!=0||n==0)return false;
        while(n>=3){
            if(n==3)return true;
            if(n%3!=0||n==0)return false;
            n/=3;
        }
        return false;
    }
};