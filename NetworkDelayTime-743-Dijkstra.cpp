class Solution {
public:
    map<int, map<int, int>> wt;
    
    vector<int> djikstra(vector<vector<int>> graph, int N, int K) {
        
        vector<int> visited(N+1, false);
        vector<int> distance(N+1, INT_MAX);
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        distance[K] = 0;
        pq.push({distance[K], K});
        while(!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();
            int node = curr.second;
            int dist = curr.first;
            
            if(visited[node]) {
                continue;
            }
            visited[node] = true;
            //cout << "Node = " << node << "Dist = " << dist << endl;
            for(int i = 0; i < graph[node].size(); i++) {
                int nhbr = graph[node][i];
                //cout << "Neighbour = " << nhbr << " ";
                if(dist + wt[node][nhbr] < distance[nhbr]) {
                    distance[nhbr] = dist + wt[node][nhbr];
                    pq.push({distance[nhbr], nhbr});
                }
            }
            
            //cout << endl;
        }
        
        return distance;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<vector<int>> graph(N+1);
        for(int i = 0; i < times.size(); i++) {
            graph[times[i][0]].push_back(times[i][1]);
            wt[times[i][0]][times[i][1]] = times[i][2];
        }
        
        vector<int> distance = djikstra(graph, N, K);
        
        /*for(int i = 1; i <= N; i++) {
            cout << i << "-->" << distance[i] << endl;
        }*/
        
        int maxm = INT_MIN;
        for(int i = 1; i <= N; i++) {
            if(distance[i] == INT_MAX) {
                return -1;
            }
            
            if(i != K && distance[i] > maxm) {
                maxm = distance[i];
            }
        }
        return maxm;
    }
};
