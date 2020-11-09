class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), designed_sort);
        return {points.begin(), points.begin()+K};
    } 
    bool static designed_sort(const vector<int>& point1, const vector<int>& point2){
        return point1[0]*point1[0]+point1[1]*point1[1] < point2[0]*point2[0]+point2[1]*point2[1];
    }
};