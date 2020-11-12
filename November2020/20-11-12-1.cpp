class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) { 
        vector<int> vec;
        if(matrix.size()==0) return vec;
        int flag = 0;
        int size = (matrix.size()) * (matrix[0].size());
        int x = 0, y = 0;
        for(int i = 0; i < size; i++){
            vec.push_back(matrix[x][y]);
            matrix[x][y] = INT_MAX;
            if(flag==0){
                if(y < matrix[0].size()-1 && matrix[x][y+1]!=INT_MAX){
                    y++;
                }else{
                    x++;
                    flag = (flag+1)%4;
                }
            }else if(flag==1){
                if(x < matrix.size()-1 && matrix[x+1][y]!=INT_MAX){
                    x++;
                }else{
                    y--;
                    flag = (flag+1)%4;
                }
            }else if(flag==2){
                if(y > 0 && matrix[x][y-1]!=INT_MAX){
                    y--;
                }else{
                    x--;
                    flag = (flag+1)%4;
                }
            }else{
                if(x > 0 && matrix[x-1][y]!=INT_MAX){
                    x--;
                }else{
                    y++;
                    flag = (flag+1)%4;
                }
            }
            // cout<<matrix[x][y]<<"  ";
        }
        return vec;
    }
};