class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        string tempstring = "";
        vector<string> st;
        for(auto f : path){
            if(f=='/'){
                if(tempstring!=""){
                    if(tempstring==".."){
                        if(st.size()!=0){
                            st.pop_back();
                        }
                    }else if(tempstring!="."){
                        st.emplace_back(tempstring);
                    }
                }
                tempstring = "";
            }else{
                tempstring += f;
            }
        }
        string ret = "/";
        for (int i = 0; i<st.size(); i++){
            ret = ret + st[i] + "/";
        }
        if(st.size()!=0){
            ret.pop_back();            
        }
        return ret;
    }
};