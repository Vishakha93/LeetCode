class Solution {
public:
    double myPow(double x, int n) {
        
        unsigned int exponent = abs((long long)n);
        double result = 1.0;
        double base = x;
        while (exponent > 0) {
            if(exponent % 2 != 0) {
                result = result * base;
            }
            exponent = exponent/2L;
            base = base * base;
        }
        
        if(n < 0){
            return 1.0/result;
        }
        
        return result;
    }
};
