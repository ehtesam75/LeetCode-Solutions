class MyHashSet {
    static const int N = 1e6 + 9;
    bool check[N] = {0};
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        check[key] = 1;
    }
    
    void remove(int key) {
        check[key] = 0;
    }
    
    bool contains(int key) {
        return check[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */