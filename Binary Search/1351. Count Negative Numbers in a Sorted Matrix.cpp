//binary search approch: time complexity O(row * log (col))

class Solution {

public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        long long ans = 0;
        for(int i = 0; i < row; i++){
            ans += grid[i].end() - lower_bound(grid[i].begin(), grid[i].end(), -1, greater<int>());
        }
        
        return ans;
    }
};

//approch two : time complexity O(row + col)

class Solution {

public:
    int countNegatives(vector<vector<int>>& grid) {
        int row(grid.size()), col(grid[0].size()), r = 0, c = col-1;
        long long ans = 0;
        while(r < row){
            while(c >= 0 and grid[r][c] < 0) c--;
            ans += col - 1 - c;
            r++;
        }

        return ans; 
    }
};

//https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/