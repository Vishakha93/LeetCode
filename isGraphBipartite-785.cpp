class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, int subset, map<int, int>& visited) {
        visited[node] = subset;
        int nextSubset = subset == 1? 2: 1;
        for(int i = 0; i<graph[node].size(); i++) {
            if(visited.find(graph[node][i]) == visited.end()) {
                if (!dfs(graph, graph[node][i], nextSubset, visited)) {
                    return false;
                }
            }
            else {
                int existingSubset = visited[graph[node][i]];
                if(existingSubset != nextSubset) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        map<int, int> visited;
        int temp;
        for(int i = 0; i<graph.size(); i++) {
            if(visited.find(i) == visited.end()) {
                temp = dfs(graph, i, 1, visited);
                if (!temp) {
                    return false;
                }
            }
        }
        return true;
    }
};
