class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        map<int, vector<vector<int>>> m;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> emptyVec;
        for(int i = 0; i < candidates.size(); i++) {
            m[candidates[i]] = emptyVec;
        }
        
        
        for(int i = 0; i < candidates.size(); i++) {
            for(int j = 1; j <= target; j++) {
                
                if(candidates[i] <= j && dp[j - candidates[i]] != 0) {
                    
                    dp[j] = dp[j] + dp[j-candidates[i]];
                    vector<vector<int>> preset = m[j-candidates[i]];
                    
                    for(int k = 0; k < preset.size(); k++) {
                        preset[k].push_back(candidates[i]);
                        m[j].push_back(preset[k]);
                    }
                    
                    if(j == candidates[i]) {
                        m[j].push_back({candidates[i]});
                    }
                }
            }
        }
        
        
        /*for(int i = 0; i <= target; i++) {
            cout << dp[i] << " ";
        }
        cout << endl;*/
        return m[target];
    }
};
