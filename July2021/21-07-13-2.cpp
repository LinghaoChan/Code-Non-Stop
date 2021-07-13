class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> zero(n, INT_MAX);
        vector<vector<int>> adj(n, zero);
        for(vector<int> edge : edges){
            adj[edge[0]][edge[1]] = edge[2];
            adj[edge[1]][edge[0]] = edge[2];
        }
        for(int i = 0; i < n; i++){
            adj[i][i] = 0;
        }
        for(int k = 0; k < n; k++){
            for(int i = 0 ; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(adj[i][k]!=INT_MAX && adj[k][j]!=INT_MAX && i!=j && adj[i][k] + adj[k][j] < adj[i][j]){
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
        int max = INT_MAX;
        int maxindex = 0;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                // cout<<adj[i][j]<<" ";
                if(i!=j && adj[i][j] <= distanceThreshold){
                    count++;
                }
            }
            // cout<<endl;
            cout<<count<<endl;
            if(count <= max){
                max = count;
                maxindex = i;
            }
        }
        return maxindex;
    }
};