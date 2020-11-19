class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){
            return {1};
        }
        if(rowIndex ==1){
            return {1, 1};
        }else if(rowIndex == 2){
            return {1, 2, 1};
        }
        vector<vector<int>> final_vec = {{1}, {1, 1}};
        for(int i = 2; i < rowIndex+1; i++){
            vector<int> vec_last = final_vec[final_vec.size() - 1];
            vector<int> vec = {1};
            for(int j = 1; j < i; j++){
                vec.emplace_back(vec_last[j-1] + vec_last[j]);
            }
            vec.emplace_back(1);
            final_vec.emplace_back(vec);
        }
        return final_vec[final_vec.size()-1];
    }
};