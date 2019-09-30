class Solution {
public:
    vector<int> cumSum;
    int sum;
    Solution(vector<int>& w) {
        sum = 0;
        for(int i = 0; i < w.size(); i++) {
            cumSum.push_back(sum + w[i]);
            sum = cumSum[i];
        }
    }
    
    int pickIndex() {
        int idx = rand()%sum;
        
        int lo = 0, hi = cumSum.size() - 1;
        
        while(lo != hi) {
            int mid = (lo + hi)/2;
            if(cumSum[mid] <= idx) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        
        return lo;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
