class MyHashSet {
    static const int N = 1e6 + 9;
    bitset<N> check;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        check.set(key);
    }
    
    void remove(int key) {
        check.reset(key);
    }
    
    bool contains(int key) {
        return check.test(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */