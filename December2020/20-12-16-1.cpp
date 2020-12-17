class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i, j;
        int sum = 0;
        int size1 = grid.size();
        int size2 = grid[0].size();
        for(i = size1-1; i>=0; i--){
            for(j = size2-1; j>=0; j--){
                if(grid[i][j]<0){
                    sum++;
                }else{
                    break;
                }
            }

        }  
        return sum;
    }
};