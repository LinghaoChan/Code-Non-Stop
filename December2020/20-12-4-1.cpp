class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), [&](int a, int b) {
            return abs(a) > abs(b);
        }); 
        for (int i = 0; i < A.size(); i++) {
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        while (K--) A[A.size() - 1] *= -1;
        int result = 0;
        for (int a : A) result += a;
        return result;
    }
};