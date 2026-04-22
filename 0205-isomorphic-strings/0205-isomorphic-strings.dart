class Solution {
  bool isIsomorphic(String s, String t) {
    Map<String, String> mp = {};
    Map<String, String> out = {};

    for(int i = 0; i < s.length; i++){
        if(!out.containsKey(t[i])){
            out[t[i]] = s[i];
        }
        if(!mp.containsKey(s[i])){
            // if(mp.containsKey(t[i]) && mp[t[i]] != s[i]){
            //     return false;
            // }
            if(out.containsKey(t[i]) && out[t[i]] != s[i]){
                return false;
            }
            mp[s[i]] = t[i];
            // mp[t[i]] = s[i];
        }
        // else if(mp.containsKey(s[i])){
        //     if(mp[s[i]] != t[i]) return false;
        // }
        // else if(mp.containsKey(t[i])){
        //     if(mp[t[i]] != s[i]) return false;
        // }
        else{
            if(mp[s[i]] != t[i]) return false;
        }
    }
    return true;
  }
}