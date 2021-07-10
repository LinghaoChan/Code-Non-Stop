class Solution {
public:
    bool BFS(unordered_map<int, unordered_set<int>> G, vector<int> indegree, int numCourses){
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int front = q.front();
            count++;
            q.pop();
            for(auto item : G[front]){
                indegree[item]--;
                if(indegree[item] == 0){
                    q.push(item);
                }
            }
        }
        cout<<count;
        return count == numCourses;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> G;
        vector<int> indegree(numCourses, 0);
        for(auto adj : prerequisites){
            int after = adj[0];
            int pre = adj[1];
            G[pre].insert(after);
            indegree[after]++;
        }
        return BFS(G, indegree, numCourses);
    }
};