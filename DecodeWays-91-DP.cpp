class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.length();
        vector<int> dp(n, 0);
        
        if(n == 0 || s[0] == '0') {
            return 0;
        }
        
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            if (s[i] != '0') {
                dp[i] = dp[i-1];
            }
            int num = (s[i-1]-'0') * 10 + (s[i]-'0');
            if(num <= 26 && num >= 10) {
                if(i == 1) {
                    dp[i]++;
                }
                else {
                   dp[i] = dp[i] + dp[i-2]; 
                }
            }
        }
        
        return dp[n-1];
    }
};
