class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> lo; //max heap
    priority_queue<int, vector<int>, greater<int>> hi; //min heap
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (hi.size() > 0 && num>hi.top()) {
            hi.push(num);
        }
        else {
            lo.push(num);
        }
        
        int n = lo.size();
        int m = hi.size();
        
        if(n > m+1) {
            int val = lo.top();
            lo.pop();
            hi.push(val);
        }
        
        if(m > n + 1) {
            int val = hi.top();
            hi.pop();
            lo.push(val);
        }
    }
    
    double findMedian() {
        
        /*priority_queue<int> temp_lo(lo);
        priority_queue<int, vector<int>, greater<int>> temp_hi(hi);
        
        cout << "Lo = " << endl;
        while(!temp_lo.empty()) {
            cout << temp_lo.top() << " ";
            temp_lo.pop();
        }
        cout << endl;
        cout << "Hi = " << endl;
        while(!temp_hi.empty()) {
            cout << temp_hi.top() << " ";
            temp_hi.pop();
        }
        cout << endl; */
        
        int size = lo.size() + hi.size();
        
        if(size%2 == 0) {
            return (double)(lo.top() + hi.top())/2.0;
        }
        else {
            return lo.size() > hi.size() ? lo.top(): hi.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
