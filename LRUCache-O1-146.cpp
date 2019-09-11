class LRUCache {
private:
    int capacity;
    list<int> lru;
    map<int, list<int>::iterator> mp;
    map<int, int> cache;
    
    void updateLRU(int key) {
        if (mp.count(key) != 0) {
            lru.erase(mp[key]);
        }
        lru.push_front(key);
        mp[key] = lru.begin();
    }
    
    void evict() {
        cache.erase(lru.back());
        mp.erase(lru.back());
        lru.pop_back();
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.count(key) == 0) {
            return -1;
        }
        updateLRU(key);
        return cache[key];
    }
    
    void put(int key, int value) {
        if(cache.size() == capacity && cache.count(key) == 0){
            evict();
        }
        updateLRU(key);
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
