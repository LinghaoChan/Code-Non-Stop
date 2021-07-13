class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }        
        vector<int> tt = {};

        vector<int> degree(n, 0);
        vector<vector<int>> vec(n, tt);
        for(vector<int> item : edges){
            int a = item[0];
            int b = item[1];
            vec[a].emplace_back(b);
            vec[b].emplace_back(a);
            degree[a]++;
            degree[b]++;
        }
        vector<int> ref(n, 0);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i]==1){
                q.push(i);
                ref[i]=1;
            }
        }
        queue<int> qtmp;
        queue<int> ret;
        while(1){
            // cout<<q.size();
            qtmp = {};
            ret = q;
            while(!q.empty()){
                int num = q.front();
                // cout<<num;
                q.pop();
                for(int i = 0; i < vec[num].size(); i++){
                    degree[vec[num][i]]--;
                    if(ref[vec[num][i]]==0 && degree[vec[num][i]]==1){
                        qtmp.push(vec[num][i]);
                        ref[vec[num][i]] = 1;
                    }
                }
            }
            if(qtmp.empty()){
                break;
            }else{
                q = qtmp;
            }
        }
        while(!ret.empty()){
            int num = ret.front();
            tt.emplace_back(num);
            ret.pop();
        }
        return tt;
    }
};