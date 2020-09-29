class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size(), len2=nums2.size();
        int i;
        vector<int> vec;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(i=0;i<len1;i++){
            int j;
            if(i!=0){
                for(j=0;j<len2;j++){
                    if(nums1[i]==nums2[j]&&nums1[i]!=nums1[i-1]){
                        vec.push_back(nums2[j]);
                        break;
                    }                
                }                
            }
            else{
                for(j=0;j<len2;j++){
                    if(nums1[i]==nums2[j]){
                        vec.push_back(nums2[j]);
                        break;
                    }                
                } 
            }
            //cout<<vec.size()<<endl;
        }
        return vec;
    }
};