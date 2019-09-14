class Solution {
public:
    
    bool isCyclic(int node, vector<int> &visited, vector<int> &ans, vector<vector<int>> &graph, unordered_map<int, int> &ancestors) {
        visited[node] = 1;
        ancestors[node] = 1;
        for(int i = 0; i < graph[node].size(); i++) {
            
            if(ancestors.find(graph[node][i]) != ancestors.end()){
                return false;
            }
            
            if(visited[graph[node][i]] == 0) {
                if(!isCyclic(graph[node][i], visited, ans, graph, ancestors)) {
                    return false;
                }
            }
        }
        ancestors.erase(node);
        ans.push_back(node);
        return true;
    }
    
    string alienOrder(vector<string>& words) {
        vector<vector<int>> graph(26);
        vector<int> visited(26, 0);
        unordered_map<int, int> ancestors;
        string order = "";
        vector<int> ans;
        vector<int> present(26, 0);
        
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                present[words[i][j]-97] = 1;
            }
        }
        
        for(int i = 0; i < words.size()-1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];
            
            int j = 0;
            while(j < s1.length() && j < s2.length()) {
                if(s1[j] != s2[j]) {
                    int node1 = s1[j] - 97;
                    int node2 = s2[j] - 97;
                    graph[node1].push_back(node2);
                    break;
                }
                j++;
            }
        }
        
        for(int i = 0;i < 26; i++) {
            if(visited[i] == 0 && graph[i].size() > 0) {
                if(!isCyclic(i, visited, ans, graph, ancestors)) {
                    return "";
                }
            }
        }
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) {
            order = order + (char)(ans[i] + 97);
        }
        
        for(int i = 0; i < 26; i++) {
            if(present[i] == 1 && visited[i] == 0) {
                order = order + (char)(i+97);
            }
        }
        return order;
    }
};
