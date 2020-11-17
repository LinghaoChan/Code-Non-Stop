class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> vec;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                vector<int> v = {i, j};
                vec.emplace_back(v);
            }
        }
        sort(vec.begin(), vec.end(), [&](vector<int> a, vector<int> b){
            return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
        });
        return vec;
    }
};