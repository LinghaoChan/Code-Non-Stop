class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i;
        int size = arr.size();
        if(size==1)return true;
        int var = arr[1]-arr[0];
        for(i=1;i<size;i++){
            if(arr[i]-arr[i-1]!=var) return false;
        }
        return true;
    }
};