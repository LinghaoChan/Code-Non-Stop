class Solution {
public:
    vector<int> BFS(int numCourses, unordered_map<int, unordered_set<int>> G, vector<int> indegree){
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> vec;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            vec.emplace_back(front);
            for(auto item : G[front]){
                indegree[item]--;
                if(indegree[item] == 0){
                    q.push(item);
                }
            }
        }
        if(vec.size() == numCourses){
            return vec;
        }else{
            return {};
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> G;
        vector<int> indegree(numCourses, 0);
        for(int i = 0 ; i < prerequisites.size(); i++){
            vector<int> pair = prerequisites[i];
            int pre = pair[1];
            int after = pair[0];
            G[pre].insert(after);
            indegree[after]++;
        }
        return BFS(numCourses, G, indegree);
    }
};