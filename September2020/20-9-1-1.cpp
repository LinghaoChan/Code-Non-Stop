class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int, int> intmap;
        vector<int> vec = {};
        int len = nums2.size();
        for(int i = 0;i < len;i++){
            if(st.size() == 0){
                st.push(nums2[i]);
            }else if(st.top()>=nums2[i]){
                st.push(nums2[i]);
            }else{
                while(st.top() < nums2[i]){
                    intmap[st.top()] = nums2[i];
                    st.pop();
                    if(st.empty()){
                        break;
                    }
                }
                st.push(nums2[i]);
            }
        }

        while(!(st.empty())){
            intmap[st.top()] = -1;
            st.pop();
        }
        vector<int> newvec = {};
        int i;
        for(i = 0;i<nums1.size();i++){
            newvec.push_back(intmap[nums1[i]]);
        }
        return newvec;
    }
};