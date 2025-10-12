//https://leetcode.com/problems/find-missing-and-repeated-values/description/

//time o(n*n) and o(N) space; (N=5007)

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        const int N = 5007;
        vector<int> freq(N, 0);
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                freq[grid[i][j]]++;
            }
        }

        int miss = -1, repeat = -1;
        for(int i = 1; i <= n * n; i++){
            if(freq[i] == 0) miss = i;
            if(freq[i] == 2) repeat = i;
        }
        return {repeat, miss};
    }
};