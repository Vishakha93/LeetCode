class Solution {
public:
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    int r, c;
    bool isValid(int x, int y)
    {
        if( x>=r || x<0 || y>=c || y<0)
            return false;
        
        return true;
    }
    
    void dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<char>> &grid)
    {
        visited[x][y] = 1;
        
        for(int i=0; i<4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if(isValid(newX, newY) && visited[newX][newY] == 0 && grid[newX][newY]=='1')
            {
                dfs(newX, newY, visited, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        
        if(r==0)
            return 0;
        
        c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, 0));
        
        int count = 0;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j] == '1' && visited[i][j] == 0)
                {
                    dfs(i, j, visited, grid);
                    count++;
                }
            }
        }
        
        return count;
    }
};
