class Solution {
public:
  
    bool isMatch(string s, string p) {
        
        int sl = s.length(), pl = p.length();
        int i, j, dp[sl+1][pl+1];
        
        dp[0][0] = true;
        
        for(i=1; i<=sl; i++)
        {
            dp[i][0] = false;
        }
        
        for(j=1; j<=pl; j++)
        {
            dp[0][j] = false;
            if(p[j-1]=='*')
            {
                dp[0][j] = dp[0][j-1];
            }
        }
        
        for(i=1; i<=sl; i++)
        {
            for(j=1; j<=pl; j++)
            {
                if(s[i-1] == p[j-1] || p[j-1]=='?')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            
        }
        return dp[sl][pl];
    }
};
