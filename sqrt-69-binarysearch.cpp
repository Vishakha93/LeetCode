class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 0 || x == 1) {
            return x;
        }
        
        int lo = 1, hi = x/2;
        
        long long num = x;
        while(lo <= hi) {
            long long mid = lo + ((hi - lo)/2);
            
            if(mid * mid == num) {
                return mid;
            }
            else if(mid * mid > num) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        
        return hi;
    }
};
