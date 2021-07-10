class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> indegree(N+1, 0);
        vector<int> outdegree(N+1, 0);
        for(auto pair : trust){
            indegree[pair[1]]++;
            outdegree[pair[0]]++;
        }
        // cout<<"dsa";
        for(int i = 1; i < N+1; i++){
            if(indegree[i] == N-1){
                if(outdegree[i] == 0){
                    return i;
                }else{
                    return -1;
                }
            }
        }
        return -1;
    }
};