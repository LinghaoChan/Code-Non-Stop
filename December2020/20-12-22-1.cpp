class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double mmax = 0;
        vector<double> res;
        for (int i = 0; i < points.size(); i ++)
            for (int j = i + 1; j < points.size(); j ++)
                for (int k = j + 1; k < points.size(); k ++) 
                    mmax = max(mmax, 0.5 * abs(points[i][0] * points[j][1] + points[i][1] * points[k][0] + points[j][0] * points[k][1] - points[i][0] * points[k][1] - points[i][1] * points[j][0] - points[j][1] * points[k][0]));
        return mmax;
    }
};