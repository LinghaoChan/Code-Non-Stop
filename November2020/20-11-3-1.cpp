class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int size = A.size();
        if(size < 3){
            return false;
        }
        int count = 0;
        int de_flag = 0;
        int in_flag = 0;
        for(int i = 1; i < size - 1; i++){
            if(A[i] < A[i-1] && A[i] < A[i+1]){
                return false;
            }if(A[i] == A[i-1] || A[i] == A[i+1]){
                return false;
            }
            if(A[i] > A[i-1]){
                in_flag = 1;
            }
            
        }
        cout<<in_flag<<de_flag;
        if(in_flag==1  && A[size-1]<A[size-2])
            return true;
        else if(size==3 && A[1]>A[0] && A[1]>A[2])
            return true;
        else
            return false;
    }
};