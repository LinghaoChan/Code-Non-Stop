class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> vec;
        while(i<size1 && j<size2){
            if(nums1[i]<nums2[j]){
                i++;
            }else if(nums1[i]>nums2[j]){
                j++;
            }else{
                vec.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return vec;
    }
};