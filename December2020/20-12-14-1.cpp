class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];   //左下角
        int y1 = rec1[1];
        int x2 = rec1[2];   //右上角
        int y2 = rec1[3];
        int x3 = rec2[0];   //左下角
        int y3 = rec2[1];
        int x4 = rec2[2];   //右上角
        int y4 = rec2[3];

        if (x2 <= x3 || x4 <= x1 || y1 >= y4 || y3 >= y2) {
            return false;
        }
        return true;
    }
};