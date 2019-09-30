class Solution {
public:
    int minDistance(string word1, string word2) {
        
        vector<vector<int>>dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        
        for(int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        
        for(int j = 0; j <= word2.size(); j++) {
            dp[0][j] = j;
        }
        
        for(int i = 1; i<= word1.size(); i++) {
            for(int j = 1; j <= word2.size(); j++) {
                
                int a = dp[i-1][j] + 1;
                int b = dp[i][j-1] + 1;
                int c = dp[i-1][j-1];
                if(word1[i-1] != word2[j-1])
                    c++;
                dp[i][j] = min(c, min(a, b));
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
