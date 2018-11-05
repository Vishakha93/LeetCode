class Solution {
public:
    
    vector<int> getRightArray(vector<int> nums)
    {
        int i, n = nums.size();
        vector<int> right;
        
        for(i=0; i<n; i++)
        {
            right.push_back(n);
        }
        
        stack<int> st;
        st.push(0);
        i = 1;
        while(i<n && !st.empty())
        {
            while(!st.empty() && nums[st.top()] < nums[i])
            {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
            i++;
        }
        
        return right;
    }
    
    vector<int> getLeftArray(vector<int> nums)
    {
        int i, n = nums.size();
        vector<int> left;
        
        for(i=0; i<n; i++)
        {
            left.push_back(-1);
        }
        
        stack<int> st;
        st.push(n-1);
        i = n-2;
        while(i>=0 && !st.empty())
        {
            while(!st.empty() && nums[st.top()] < nums[i])
            {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
            i--;
        }
        
        return left;
    }
    
    int getNextGreaterLeftAndRight(vector<int>& nums) {
        
        int i;
        vector<int> right = getRightArray(nums);
        
        for(i=0; i<right.size(); i++)
        {
            printf("%d ", right[i]);
        }
        printf("\n");
        
        vector<int> left = getLeftArray(nums);
        
        for(i=0; i<left.size(); i++)
        {
            printf("%d ", left[i]);
        }
        printf("\n");
        
        return -1;
    }
};
