class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        
        int i, pos1 = -1, pos2 = -1,  n = arr.size();
        
        for(i=n-2; i>=0; i--)
        {
            if(arr[i] < arr[i+1])
            {
                pos1 = i;
                break;
            }
        }
        
        if(pos1 == -1)
        {
            sort(arr.begin(), arr.end());
            return;
        }
        
        int minm = INT_MAX;
        for(i=pos1+1; i<n; i++)
        {
            if(arr[i] > arr[pos1])
            {
                int diff = arr[i] - arr[pos1];
                if(diff < minm)
                {
                    minm = diff;
                    pos2 = i;
                }
            }
        }

        int temp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = temp;
        
        sort(arr.begin()+pos1+1, arr.end());
    }
};
