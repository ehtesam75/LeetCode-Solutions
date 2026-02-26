class MyHashSet {
    //approch 2 
    static const int N = 1e6 + 9; 
    static const int bracket_size = 769;
    vector<int> store[bracket_size];
    int find_bracket(int n){
        return n % bracket_size;
    }

    //approch 1 : using bitset/bool
    // bitset<N> check;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        // check.set(key);

        int idx =  find_bracket(key);
        auto it = find(store[idx].begin(), store[idx].end(), key);
        if(it == store[idx].end()){
            store[idx].push_back(key);
        }
    }   
    
    void remove(int key) {
        // check.reset(key);

        int idx =  find_bracket(key);
        auto it = find(store[idx].begin(), store[idx].end(), key);
        if(it != store[idx].end()){
            store[idx].erase(it);
        }
    }
    
    bool contains(int key) {
        // return check.test(key);

        int idx =  find_bracket(key);
        auto it = find(store[idx].begin(), store[idx].end(), key);
        return it != store[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */