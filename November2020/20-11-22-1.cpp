class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return;
        }
        set<int> row, col;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                    cout<<j<<" "<<i<<endl;
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        cout<<row.size();
        set<int> :: iterator itr = row.begin();
        for(itr=row.begin();itr!=row.end();itr++){
            int r = *itr;
            // cout<<r<<endl;
            for(int i = 0; i < matrix[0].size(); i++){
                matrix[r][i]=0;
            }
        }
        for(itr=col.begin();itr!=col.end();itr++){
            int c = *itr;
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][c]=0;
            }
        }
    }
};