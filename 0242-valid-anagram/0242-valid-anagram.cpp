class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() < s.size()) return 0;
        
        map<char, int> mp_s;
        for(auto x : s){
            mp_s[x]++;
        }

        map<char, int> mp_t;
        for(auto x : t){
            mp_t[x]++;
        }

        for(auto x : t){
            if(mp_t[x] != mp_s[x]) return 0;
        }
        return 1;
    }
};