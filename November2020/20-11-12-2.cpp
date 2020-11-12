class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int j = 1;
        int i;
        for(i = 0; i < A.size(); i+=2){
            if(A[i]&1==1){
                while(A[j]&1==1){
                    j+=2;
                }
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};