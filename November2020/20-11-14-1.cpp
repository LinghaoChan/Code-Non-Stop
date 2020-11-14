class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for(int i = 0; i < arr2.size(); i++){
            m[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int x, int y){
            if(m.count(x) > 0){
                return (m.count(y) ? m[x]<m[y] : true);
            }else{
                return (m.count(y) ? false : x<y);
            }
        });
        return arr1;
    }
};