class NumMatrix {
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        prefix = vector<vector<int>>(row, vector<int>(col, 0));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                prefix[i][j] = matrix[i][j];
                if(i > 0) prefix[i][j] += prefix[i-1][j];
                if(j > 0) prefix[i][j] += prefix[i][j-1];
                if(i > 0 and j > 0) prefix[i][j] -= prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = prefix[row2][col2];
        if(row1 > 0) total -= prefix[row1-1][col2];
        if(col1 > 0) total -= prefix[row2][col1-1];
        if(row1 > 0 and col1 > 0) total += prefix[row1-1][col1-1];
        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */