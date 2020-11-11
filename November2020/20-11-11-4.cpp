class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();

        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
        for(int i = 0; i < size; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};