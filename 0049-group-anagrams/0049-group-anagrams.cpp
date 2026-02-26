class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp = strs;
        for(int i = 0; i < temp.size(); i++){
            sort(temp[i].begin(), temp[i].end());
        }

        map<string, vector<string>> mp;
        for(int i = 0; i < temp.size(); i++){
            mp[temp[i]].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};