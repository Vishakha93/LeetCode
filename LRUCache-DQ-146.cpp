class LRUCache {
public:
    
    int capacity;
    map<int, int> m;
    list<int> dq;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
    
        if(m.find(key) == m.end())
            return -1;
        
        list<int>::iterator it  = find(dq.begin(), dq.end(),key);
        if(it != dq.end())
        {
            dq.erase(it);
        }
        
        dq.push_front(key);
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key) == m.end())
        {
            //Key not present in cache. Size of cache will increase.
            if(m.size() == this->capacity && dq.size() > 0)
            {
                int num = dq.back();
                dq.pop_back();
                m.erase(num);
            }
            
            dq.push_front(key);
            m.insert({key, value});
        }
        else
        {
            //Key present in cache
             list<int>::iterator it  = find(dq.begin(), dq.end(),key);
            if(it != dq.end())
            {
                dq.erase(it);
            }
            dq.push_front(key);
            m[key] = value;
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
