class Solution {
public:
    map<int, map<int, int>> wt;
    
    int dijkstra(int n, vector<vector<int>> graph, int src, int dst, int k) {
        
        vector<int> visited(n, false);
        vector<vector<int>> distance(n, vector<int>(k+1, INT_MAX));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        distance[src][0] = 0;
        pq.push({distance[src][0], src});
        
        while(!pq.empty()) {
            
            pair<int, int> curr = pq.top();
            pq.pop();
            
            int node = curr.second;
            if(visited[node])
                continue;
            visited[node] = true;
            for(int i = 0; i < graph[node].size(); i++) {
                int nhbr = graph[node][i];
                for(int j = 0; j < k; j++) {
                    long long sum = (long long)distance[node][j] + (long long)wt[node][nhbr];
                    if(sum < distance[nhbr][j+1]) {
                        distance[nhbr][j+1] = sum;
                        pq.push({distance[nhbr][j+1], nhbr});
                    }
                }
            }
        }
        
        int minm = INT_MAX;
        for(int i = 0; i <= k; i++) {
            if(distance[dst][i] < minm) {
                minm = distance[dst][i];
            }
        }
        
        if(minm == INT_MAX) {
            return -1;
        }
        
        return minm;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<vector<int>> graph(n);
        for(int i = 0; i < flights.size(); i++) {
            graph[flights[i][0]].push_back(flights[i][1]);
            wt[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        
        int ans = dijkstra(n, graph, src, dst, K+1);
        return ans;
    }
};
