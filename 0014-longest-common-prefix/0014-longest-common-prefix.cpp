class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = INT_MAX;
        for(int i = 0; i < strs.size(); i++){
            min_len = min(min_len, (int)strs[i].length());
        }

        string ans;
        for(int k = 0; k < min_len; k++){
            int i = 0;
            for(    ; i < (int)strs.size() - 1; i++){
                if(strs[i][k] != strs[i+1][k]){
                    return ans;
                }
            }
            ans += strs[i][k];
        }
        return ans;
    }
};