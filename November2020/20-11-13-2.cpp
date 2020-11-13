class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if(A.empty()){
            return A;
        }
        vector<vector<int>> v;
        int size1 = A.size();
        int size2 = A[0].size();
        for(int i = 0; i < size2; i++){
            vector<int> tmp;
            for(int j = 0; j < size1; j++){
                tmp.emplace_back(A[j][i]);
            }
            v.emplace_back(tmp);
        }
        return v;
    }
};