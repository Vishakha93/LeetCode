class Solution {
public:
    vector<int> v[10005];
    
    int bfs(int x, int n, int target)
    {
        int rear = 0, front = 0, q[10005], dist[10005] = {INT_MAX}, visited[10005] = {0};
        dist[x] = 1;
        visited[x] = 1;
        q[rear] = x;
        rear++;
        
        while(front < rear)
        {
            int top = q[front];
            front++;
            
            for(int i=0; i<v[top].size(); i++)
            {
                if(visited[v[top][i]]==0)
                {
                    dist[v[top][i]] = dist[top] + 1;
                    q[rear] = v[top][i];
                    rear++;
                    visited[v[top][i]] = 1;
                }
            }
        }
        
        return dist[target];
    }
    
    bool isSingleCharDiff(string x, string y)
    {
        int count = 0;
        for(int i=0; i<x.length(); i++)
        {
            if(x[i]!=y[i])
            {
                count++;
            }
        }
        
        return count==1? true: false;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int i, j, n = wordList.size(), target = -1;
        
        for(i=0; i<n; i++)
        {
            if(wordList[i] == endWord)
            {
                target = i;
            }
        }
        
        if(target == -1)
        {
            return 0;
        }
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(isSingleCharDiff(wordList[i], wordList[j]))
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        
        /*for(i=0; i<n; i++)
        {
            printf("i=%d->", i);
            for(j=0; j<v[i].size(); j++)
            {
                printf("%d ", v[i][j]);
            }
            printf("\n");
        }*/
        vector<int> source;
        for(i=0; i<n; i++)
        {
            if(isSingleCharDiff(wordList[i], beginWord))
            {
                source.push_back(i);
            }
        }
        
        int x, minmDist = INT_MAX;
        for(i=0; i<source.size(); i++)
        {
            x = bfs(source[i], n, target);
            
            if(x!=0 && x<minmDist)
            {
                minmDist = x;
            }
        }
        
        if(minmDist == INT_MAX)
        {
            minmDist = 0;
        }
        else
        {
            minmDist++;
        }
        
        return minmDist;
    }
};
