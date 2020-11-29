class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int s = A.size();
        for(int i = s-1; i>=2; i--){
            if(A[i-1]+A[i-2] > A[i]){
                return A[i-1]+A[i-2]+A[i];
            }
        }
        return 0;
    }
};