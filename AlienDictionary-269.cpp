class Solution {
public:
    
    bool isCycle(int idx, vector<vector<int>> &graph, vector<int> &visited, vector<int> &current, stack<int> &s)
    {
        visited[idx] = 1;
        bool res;
        
        current[idx] = 1;
        for(int i=0; i<graph[idx].size(); i++)
        {
            if(visited[graph[idx][i]] == 0)
            {
                if(isCycle(graph[idx][i], graph, visited, current, s))
                    return true;
            }
            else if(current[graph[idx][i]] == 1)
            {
                return true;
            }
        }
        
        current[idx] = 0;
        s.push(idx);
        return false;
    }
    string alienOrder(vector<string>& words) {
        
        int l = words.size();
        vector<vector<int>> graph(26, vector<int>());
        vector<int> visited(26, 0);
        vector<int> current(26, 0);
        vector<int> hash(26, 0);
        stack<int> s;
        
        if(l==0)
            return "";
        
        for(int i=0; i<l; i++)
        {
            for(int j = 0; j<words[i].length(); j++)
            {
                hash[words[i][j]-'a'] = 1;
            }
        }
        
        for(int i=1; i<l; i++)
        {
            int j = 0;
            while(j < words[i-1].length() && j<words[i].length())
            {
                int idx1 = words[i-1][j] - 'a';
                int idx2 = words[i][j] - 'a';
                j++;
                
                if(idx1 == idx2)
                {
                    continue;
                }
                if(find(graph[idx1].begin(), graph[idx1].end(), idx2) != graph[idx1].end())
                {
                    break;
                }
                
                graph[idx1].push_back(idx2);
                break;
            }
        }
        
        for(int i=0; i<26; i++)
        {
            if(graph[i].size()>0 && visited[i] == 0)
            {
                if(isCycle(i, graph, visited, current, s))
                {
                    return "";
                }
            }
        }
        
        string ans = "";
        while(!s.empty())
        {
            int ascii = s.top() + 'a';
            s.pop();
            string str(1, (char)ascii);
            ans = ans + str;
        }
        
        for(int i=0; i<26; i++)
        {
             string str(1, (char)i+'a');
             if(hash[i] == 1 && ans.find(str) == string::npos)
             {
                 ans = ans + str;
             }
        }
        
        return ans;
    }
};
