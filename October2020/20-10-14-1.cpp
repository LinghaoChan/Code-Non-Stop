class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        if(A.empty()){
            return A;
        }
        int count[26];
        for(int i = 0; i < 26; i++){
            count[i] = 0;
        }
        for(int i = 0; i < A.size(); i++){
            string tmp = A[i];
            int count_tmp[26]={0};
            for(int j = 0; j < tmp.length(); j++){
                char t = tmp[j];
                int tt = t - 'a';
                count_tmp[tt]++;
            }
            if(i!=0){
                for(int j = 0; j < 26; j++){
                    count[j] = (count[j] < count_tmp[j] ? count[j] : count_tmp[j]);
                    // cout<<count[j]<<' ';
                } 
                // cout<<endl;
            }else{
                for(int j = 0; j < 26; j++){
                    count[j] = count_tmp[j];
                    // cout<<count[j]<<' ';
                } 
                // cout<<endl;
            }

        }
        vector<string> vec;
        for(int i = 0; i < 26; i++){
                // cout<<count[i]<<' ';
            for(int j = 0; j < count[i]; j++){
                char t = i+'a';
                string s;
                s.push_back(t);
                vec.push_back(s);
            }
        }
        return vec;
    }
};