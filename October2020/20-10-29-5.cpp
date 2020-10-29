class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> vec;
        for(int i = 0; i < k; i++){
            vec.emplace_back(arr[i]);
        }
        return vec;
    }
};