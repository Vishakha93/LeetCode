class Solution {
public:
    void swap(int &a, int &b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    
    int recr(vector<int>& arr, int start, int end, int k)
    {
        int temp;
        if(start > end)
            return INT_MAX;
        
        if(start == end)
        {
            return arr[start];
        }
        
        int l = start;
        
        for(int i = start; i<end; i++)
        {
            if(arr[i] < arr[end])
            {
                swap(arr[i], arr[l]);
                l++;
            }
        }
        swap(arr[l], arr[end]);
        int diff = end - l +1;
        if(diff == k)
            return arr[l];
        
        if(k>diff)
        {
            k = k - diff;
            return recr(arr, start, l-1, k);
        }
        else
        {
            return recr(arr, l+1, end, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        int ans = recr(nums, 0, nums.size()-1, k);
        return ans;
        
    }
};
