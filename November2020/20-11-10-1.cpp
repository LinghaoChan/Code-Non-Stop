class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for(int i = size - 1; i >= 0; i--){
            digits[i]++;
            if(digits[i]!=10){
                return digits;
            }else{
                digits[i] = 0;
            }
        }
        vector<int> p = {1};
        for(int i = 0; i<size; i++){
            p.emplace_back(0);
        }
        return p;
    }
};