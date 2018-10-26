class Trie
{
    
public:
    bool isLeaf;
    Trie* children[26];
    
    Trie()
    {
        this->isLeaf = false;
        for(int i=0; i<26; i++)
        {
            this->children[i] = NULL;
        }
    }
    
    void insert(string word)
    {
        Trie* root = this;
        
        for(int i = 0; i<word.length(); i++)
        {
            int idx = word[i] - 'a';
            if(root->children[idx]==NULL)
            {
                Trie* node = new Trie();
                root->children[idx] = node;
            }
            
            root = root->children[idx];
        }
        
        root->isLeaf = true;
    }
    
    bool search(string word)
    {
        Trie* root = this;
        for(int i = 0; i<word.length(); i++)
        {
            int idx = word[i] - 'a';
            if(root->children[idx]==NULL)
            {
                return false;
            }
            
            root = root->children[idx];
        }
        
        return root->isLeaf;
    }
    
    bool isPrefix(string word)
    {
        Trie* root = this;
        for(int i = 0; i<word.length(); i++)
        {
            int idx = word[i] - 'a';
            if(root->children[idx]==NULL)
            {
                return false;
            }
            
            root = root->children[idx];
        }
        
        return true;
    }
    
};

class Solution {
public:
    map<pair<int, int>, int> visited;
    vector<string> res;
    int r, c;
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    Trie* buildTrie(vector<string> words)
    {
        Trie *trie = new Trie();
        for(int i=0; i<words.size(); i++)
        {
            trie->insert(words[i]);
        }
        
        return trie;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        r = board.size();
        
        if(r==0)
        {
            return res;
        }
        
        c = board[0].size();
        if(c==0)
        {
            return res;
        }
        
        Trie *trie = buildTrie(words);
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                dfs(board, i, j, "", trie);
            }
        }
        
        set<string> s(res.begin(), res.end());
        vector<string> ans(s.begin(), s.end());
        
        return ans;
    }
    
    void dfs(vector<vector<char>>& board, int x, int y, string s, Trie* trie)
    {
        
        if(x<0 || x>=r || y<0 || y>=c)
        {
            return;
        }
        if(visited[{x, y}] == 1)
        {
            return;
        }
        //cout << "String so far " << s << endl;
        s = s+board[x][y];
        if(!trie->isPrefix(s))
        {
            //cout << "Prefix not found for " << s << endl;
            return;
        }
        
        if(trie->search(s))
        {
            res.push_back(s);
        }

        visited[{x, y}] = 1;
        for(int i=0; i<4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            dfs(board, newX, newY, s, trie); 
        }
        
        visited[{x,y}] = 0;
    }
    
};
