class MyHashMap {

    static const int N = 1e6 + 9; 
    static const int bracket_size = 769;
    vector<pair<int, int>> store[bracket_size];
    int find_bracket(int n){
        return n % bracket_size;
    }

public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int idx =  find_bracket(key);
        bool found = 0;
        for(int i = 0; i < store[idx].size(); i++){
            if(store[idx][i].first == key){
                found = 1;
                store[idx][i].second = value;
                break;
            }
        }
        if(!found){
            store[idx].push_back({key, value});
        }
    }
    
    int get(int key) {
        int idx =  find_bracket(key);
        bool found = 0;
        for(auto &x : store[idx]){
            if(x.first == key){
                found = 1;
                return x.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx =  find_bracket(key);
        for(int i = 0; i < store[idx].size(); i++){
            if(store[idx][i].first == key){
               store[idx].erase(store[idx].begin() + i);
            }
        }      
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */