class Solution {
public:
    int maxArea(vector<int>& height) {
        int pre =0, aft = height.size()-1;
        int return_pre = pre, return_aft = aft;
        int size = 0;
        while(pre<aft){
            if(min(height[pre], height[aft])*(aft-pre)>size){
                size=(height[pre]<height[aft]? height[pre]:height[aft])*(aft-pre);
                return_pre = pre;
                return_aft = aft;
            }
            if(height[pre]<height[aft]){
                pre++;
            }else{
                aft--;
            }
        }
        return size;
    }
    int min(int a, int b){
        return (a < b)? a : b;
    }
};