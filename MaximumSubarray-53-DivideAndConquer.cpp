struct triplet {
    int sum;
    int maxLeft;
    int maxRight;
};

typedef struct triplet Triplet;
class Solution {
public:
    int maxm = INT_MIN;
    Triplet findMax(vector<int>& nums, int left, int right) {
        
        Triplet curr;
        if(left == right) {
            curr.sum = curr.maxLeft = curr.maxRight = nums[left];
            maxm = max(maxm, nums[left]);
            return curr;
        }
        
        int mid = (left + right)/2;
        Triplet resL = findMax(nums, left, mid);
        Triplet resR = findMax(nums, mid+1, right);
        
        curr.maxRight = max(resR.sum + resL.maxRight, resR.maxRight);
        curr.maxLeft = max(resL.sum + resR.maxLeft, resL.maxLeft);
        curr.sum = resL.sum + resR.sum;
        
        maxm = max(maxm, curr.maxRight);
        maxm = max(maxm, curr.maxLeft);
        maxm = max(maxm, resL.maxRight + resR.maxLeft);
        return curr;
    }
    
    int maxSubArray(vector<int>& nums) {
        findMax(nums, 0, nums.size()-1);
        return maxm;
    }
    
};
